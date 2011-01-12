package classes;

public class Instrucoes {
	
	public static int istatic = 123;
	public int i = 456;
	
	public void testeStaticFields() {
		System.out.println(istatic);
		System.out.println(new Instrucoes().i);
	}
	
	public void testeFields() {
		Instrucoes m = new Instrucoes();
		System.out.println(m.i);
		m.i = 4;
		System.out.println(m.i);
	}
	
	public void instancia() {
		new Instrucoes();
	}

}
