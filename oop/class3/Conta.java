public class Conta {
	private String numero;
	private String titular;
	private double saldo;

	public Conta(String titular, String numero)	{
		this.titular = titular;
		this.numero = numero;
		this.saldo = 0;
	}

	public void depositar(double valor) {
		this.saldo += valor;
	}

	public void sacar(double valor) {
		this.saldo -= valor;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}
	
	public String getNumero() {
		return this.numero;
	}

	public void setTitular(String titular) {
		this.titular = titular;
	}

	public String getTitular() {
		return this.titular;
	}

	public double getSaldo() {
		return this.saldo;
	}

	public String toString() {
		return "Numero.: " + this.getNumero() +
			" | Titular: " + this.getTitular() +
			" | Saldo..: " + this.getSaldo();
	}
}
