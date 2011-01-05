package classes.deboa;

public class Gerente extends Funcionario {
	
	public static int cod_ger = 2;
	
	public Gerente(String nome) {
		super(nome);
	}
	
	public void receber() {
		System.out.println("Gerente recebe muito");
	}

}
