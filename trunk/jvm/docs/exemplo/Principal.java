package classes.deboa;

public class Principal {

	public static void main(String[] args) {
		Gerente g = new Gerente("Ladeira");
		boolean b = estatico(g);
		System.out.println(b);
		
		int a[][] = {
				{3, 321, 32, 33, 1}, 
				{9, 5, 34, 543, 541} 
		};
		System.out.println(a[1][4]);
		System.out.println(a.length);
		System.out.println(a[0].length);
	}
	
	public static boolean estatico(Gerente parametro) {
		System.out.println(parametro.getNome());
		parametro.idade = 100.589346F / 3F + 7.8F;
		parametro.idade %= 35;
		System.out.println(parametro.idade);
		parametro.trabalhar();
		parametro.receber();
		
		System.out.println(Funcionario.cod_fun);
		
		return true;
	}

}
