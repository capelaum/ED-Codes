
//http://www.bogotobogo.com/Algorithms/compression_huffman_encoding.php

#include <stdio.h>
#include <string.h>
 
typedef struct node_t {
	struct node_t *left, *right;
	int freq;
	char c;
} *node;
 
struct node_t pool[256] = {{0}};
node qqq[255], *q = qqq - 1;
int n_nodes = 0, qend = 1;
char *code[128] = {0}, buf[1024];


node new_node(int freq, char c, node a, node b)
{
	node n = pool + n_nodes++;
	if (freq) n->c = c, n->freq = freq;
	else {
		n->left = a, n->right = b;
		n->freq = a->freq + b->freq;
	}
	return n;
}
 
/* priority queue */
void qinsert(node n)
{
	/* higher freq has lower priority
	   move up lower freq */
	int j, i = qend++;
	while ((j = i / 2)) {
		/* compare freq of the new node with the parent's freq */
		if (q[j]->freq <= n->freq) break;
		q[i] = q[j], i = j;
	}
	q[i] = n;
}

/* remove the top element(q[1]), 
   and moving up other elements */
node qremove()
{
	int i, l;
	node n = q[i = 1];
 
	if (qend < 2) return 0;
	qend--;
	while ((l = i * 2) < qend) {
		if (l + 1 < qend && q[l + 1]->freq < q[l]->freq) l++;
		q[i] = q[l], i = l;
	}
	q[i] = q[qend];
	return n;
}
 
/* walk the tree and put 0s and 1s */
void build_code(node n, char *s, int len)
{
	static char *out = buf;
	if (n->c) {
		s[len] = 0;
		strcpy(out, s);
		code[n->c] = out;
		out += len + 1;
		return;
	}
 
	s[len] = '0'; build_code(n->left,  s, len + 1);
	s[len] = '1'; build_code(n->right, s, len + 1);
}
 
void init(const char *s)
{
	int i, freq[128] = {0};
	char c[16];
 
	/* count frequency for each character */
	while (*s) freq[(int)*s++]++;
 
	/* initial heap tree */
	for (i = 0; i < 128; i++) {
		if (freq[i]) qinsert(new_node(freq[i], i, 0, 0));
	}
	
	/* complete heap while merging node staring from the lower frequency nodes */
	/* This is done in the following steps
	   (1) remove top two nodes which have the highest priority (lowest freq)
	   (2) make a new one with the two removed nodes while adding the two freqs
	   (3) when we make the new node, it remembers its children as left/right nodes
	   (4) keep merging the nodes until there is only one node left
	*/
	while (qend > 2) {
		qinsert(new_node(0, 0, qremove(), qremove()));
	}
 
	/* (1) Traverse the constructed tree from root to leaves 
	   (2) Assign and accumulate 
	   a '0' for left branch and a '1' for the right branch at each node. 
	   (3) The accumulated zeros and ones at each leaf constitute a Huffman encoding
	*/
	build_code(q[1], c, 0);
}
 
void encode(const char *s, char *out)
{
	while (*s) {
		strcpy(out, code[*s]);
		out += strlen(code[*s++]);
	}
}
 
void decode(const char *s, node t)
{
	node n = t;
	while (*s) {
		if (*s++ == '0') n = n->left;
		else n = n->right;
 
		if (n->c) putchar(n->c), n = t;
	}
 
	putchar('\n');
	if (t != n) printf("garbage input\n");
}

int main(void)
{
	const char *str = "this is an example for huffman encoding";
	char buf[1024];
 
	init(str);
	for (int i = 0; i < 128; i++) 
		if (code[i]) printf("'%c': %s\n", i, code[i]);
 
	encode(str, buf);
	printf("encoded: %s\n", buf);
 
	printf("decoded: ");
	decode(buf, q[1]);
 
	return 0;
}