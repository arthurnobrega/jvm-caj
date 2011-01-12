package classes.deboa;

public class Funcionario {
	
	public static int cod_fun = 1;
	
	private String nome;
	public float idade;

	public Funcionario(String nome) {
		this.nome = nome;
	}
	
	public void trabalhar() {
		System.out.println("Funcionario trabalha");
	}

	public void receber() {
		System.out.println("Funcionario recebe");
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

}
