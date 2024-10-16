class RunThE implements Runnable {
	private long N;
	private int MaxThreads;
	// resultado da operação
	public double valor;
	// construtor
	public RunThE(long aN, int aMaxThreads) {
		N = aN;
		MaxThreads = aMaxThreads;
	}
	public void run() {
		int k;
		double p = 1, x, y;
		x = 1 + 1.0/N;
		for(k=0 ;k<N/MaxThreads; k++)
		p = p*x;
		valor = p;
	}
}
