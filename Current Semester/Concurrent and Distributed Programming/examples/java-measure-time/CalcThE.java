public class CalcThE { 
	public static void main(String args[]) throws InterruptedException{
		
		if(args.length != 1 || !args[0].matches("\\d*[^0]\\d*")) {
			System.err.println("usage: java CalcThE MaxThreads.");
			System.exit(1);
		}
		
		int MaxThreads = Integer.parseInt(args[0]);
		int i;
		long N = 1000000000;
		Thread[] th;
		RunThE[] rh;
		double resfinal;
		rh = new RunThE[MaxThreads];
		th = new Thread[MaxThreads];
		
		//pre-proc
//		Thread.sleep(1000);
		
		long startTime = System.currentTimeMillis();
		for(i=0; i<MaxThreads; i++) {
			rh[i] = new RunThE(N, MaxThreads);
			th[i] = new Thread(rh[i]);
			th[i].start();
		}
		resfinal = 1;
		for(i=0; i<MaxThreads; i++) {
			th[i].join();
			resfinal *= rh[i].valor;
		}
		long calcTime = System.currentTimeMillis() - startTime;
		
		//pos-proc
//		Thread.sleep(1000);
		
		System.out.println("Resultado=" + resfinal);
		System.out.println("Em " + calcTime + "ms.\n");
	}
}
