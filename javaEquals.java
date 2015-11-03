class Untitled {
	public static void main(String[] args) {
		String s = "Yo mama"; 
		String l = "Yo mama"; 
		
		if (s == "Yo mama") {
			System.out.println(" == returns true");
		}
		
		if (s.compareTo(l) == 0) {
			System.out.println("compareTo is true!");
		}
		
		if (s.equals(l)) {
			System.out.println(".equals returns true");
		}
	}
}
