void ByteMult(unsigned long * a, unsigned long * b,unsigned long * c,long n){
	long i = 0, j = 0, k = 0;
	unsigned long sum;
	int limit = (n/8) * 8;
	for(i = 0;i < n; i++){
		long in = i * n;
		for(j = 0; j < n; j++){
			sum = 0;
			for(k = 0; k < limit; k+=4){
				sum = sum + a[in + k] * b[k * n + j];
				sum = sum + a[in + (k + 1)] * b[(k+1) * n + j];
				sum = sum + a[in + (k + 2)] * b[(k+2) * n + j];
				sum = sum + a[in + (k + 3)] * b[(k+3) * n + j];
				sum = sum + a[in + (k + 4)] * b[(k+4) * n + j];
				sum = sum + a[in + (k + 5)] * b[(k+5) * n + j];
				sum = sum + a[in + (k + 6)] * b[(k+6) * n + j];
				sum = sum + a[in + (k + 7)] * b[(k+7) * n + j];
			}
			if(k < n){
				switch(n - k){
					case 8: sum = sum + a[in + (k + 8)] * b[(k + 8) * n + j];
					case 7: sum = sum + a[in + (k + 6)] * b[(k + 6) * n + j];				
					case 6: sum = sum + a[in + (k + 5)] * b[(k + 5) * n + j];
					case 5: sum = sum + a[in + (k + 4)] * b[(k + 4) * n + j];				
					case 4: sum = sum + a[in + (k + 3)] * b[(k + 3) * n + j];				
					case 3: sum = sum + a[in + (k + 2)] * b[(k + 2) * n + j];
					case 2: sum = sum + a[in + (k + 1)]	* b[(k + 1)	* n + j];
					case 1: sum = sum + a[in + k] * b[k * n + j];			
				}z
			}
			c[in + j] = sum;
		}
	}
}


