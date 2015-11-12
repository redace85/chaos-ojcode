void printAA(int *a[], int s,int *cs){
	puts("------ start ------");
	int i=0;
	while(i<s){
		int *sa=a[i];

		int j=0;
		int end = cs[i];
		while(j<end){
			printf("%d,",sa[j]);
			++j;
		}
		printf("end line %d\n",i);

		++i;
	}
	puts("------ stop ------");
}

