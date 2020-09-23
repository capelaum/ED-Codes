



public static void compress() {
   String s = BinaryStdIn.readString();
   char[] input = s.toCharArray();

   // cálculo da tabela de códigos st[]
   // discutido mais adiante

   for (int i = 0; i < input.length; i++) {
      String code = st[input[i]];
      for (int j = 0; j < code.length(); j++)
      if (code.charAt(j) == '1')
           BinaryStdOut.write(true);
      else BinaryStdOut.write(false);
   }
   BinaryStdOut.close();
}

private static class Node implements Comparable<Node> {
   private char ch;   // usado só nas folhas
   private int freq;  // usado só para construção da trie
   private final Node left, right;

   Node(char ch, int freq, Node left, Node right) {
       this.ch = ch;
       this.freq = freq;
       this.left = left;
       this.right = right;
   }

   public boolean isLeaf() { 
      return left == null && right == null; 
   }

   public int compareTo(Node that) { 
      return this.freq - that.freq; 
   }
}

public static void expand() {
   Node root = readTrie();        // discutido abaixo
   int N = BinaryStdIn.readInt(); // comprimento da string original

   for (int i = 0; i < N; i++) {  // decodifica próximo caractere
      Node x = root;
      while (!x.isLeaf())
         if (BinaryStdIn.readBoolean())
              x = x.right;
         else x = x.left;
      BinaryStdOut.write(x.ch);
   }
   BinaryStdOut.close();
}

private static Node buildTrie(int[] freq) {
   MinPQ<Node> pq = new MinPQ<Node>();
   for (char c = 0; c < R; c++)
      if (freq[c] > 0)
         pq.insert(new Node(c, freq[c], null, null));

   while (pq.size() > 1) { 
      Node x = pq.delMin();
      Node y = pq.delMin();
      Node parent = new Node('\0', x.freq + y.freq, x, y);
      pq.insert(parent);
   }
   return pq.delMin();
}

private static String[] buildCode(Node root) { 
   String[] st = new String[R];
   buildCode(st, root, "");
   return st;
}

private static void buildCode(String[] st, Node x, String s) { 
   if (x.isLeaf()) { 
      st[x.ch] = s; 
      return; 
   }
   buildCode(st, x.left, s + '0');
   buildCode(st, x.right, s + '1');
}

public static void compress() {
   String s = BinaryStdIn.readString();
   char[] input = s.toCharArray();

   int[] freq = new int[R];
   for (int i = 0; i < input.length; i++)
      freq[input[i]]++;

   Node root = buildTrie(freq);

   String[] st = new String[R];
   buildCode(st, root, "");

   writeTrie(root);  // discutido abaixo

   BinaryStdOut.write(input.length);

   for (int i = 0; i < input.length; i++) {
      String code = st[input[i]];
      for (int j = 0; j < code.length(); j++)
      if (code.charAt(j) == '1')
           BinaryStdOut.write(true);
      else BinaryStdOut.write(false);
   }
   BinaryStdOut.close();
}

// Discuta maneira alternativa de calcular as freqs
int[] freq = new int[R];
   for (int c = 0; c < R; c++)
      for (int i = 0; i < input.length; i++)
         if (input[i] == c) freq[c]++;
         
         
         
private static void writeTrie(Node x) {
   if (x.isLeaf()) {
      BinaryStdOut.write(true);
      BinaryStdOut.write(x.ch);
      return;
   }
   BinaryStdOut.write(false);
   writeTrie(x.left);
   writeTrie(x.right);
}

private static Node readTrie() {
   if (BinaryStdIn.readBoolean()) {
      char c = BinaryStdIn.readChar();
      return new Node(c, 0, null, null);
   }
   return new Node('\0', 0, readTrie(), readTrie());
}


public class Huffman {

   private static int R = 256; // alfabeto ASCII
   
   private static class Node implements Comparable<Node> { /* veja acima */ }

   public static void expand() { /* veja acima */ }

   private static Node buildTrie(int[] freq) { /* veja acima */ }

   private static String[] buildCode(Node root) { /* veja acima */ }

   public static void compress() { /* veja acima */ } 

   private static void writeTrie(Node x) { /* veja acima */ } 

   private static Node readTrie() { /* veja acima */ } 

}
