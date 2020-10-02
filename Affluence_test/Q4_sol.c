int findPrevious(int num) 
{ 
    int n = 0, N = num;
    while (N != 0) {
        N /= 10;     
        ++n;
    }
    
    char number[n];
    sprintf(number, "%d", num); 
    
    int i, j; 
  
    
    for (i = n - 1; i > 0; i--) 
        if (number[i] < number[i - 1]) 
            break; 
  
    
    if (i == 0) { 
        printf("Previous number is not possible"); 
        return 0; 
    } 
  
    
    int x = number[i - 1], greatest = i; 
    for (j = i; j < n; j++) 
        if (number[j] < x && number[j] > number[greatest]) 
            greatest = j; 
  
    char temp = number[greatest];
    number[greatest] = number[i - 1];
    number[i - 1] = temp;
  
    for(int k = i ; k< n-1; k++){
        if(number[k] < number[k+1]){
            temp = number[k];
            number[k] = number[k+1];
            number[k+1] = temp;
        }
    }
  
    printf("Immediate smaller number with same set of digits is %s",number); 
    
    sscanf(number, "%d", &N);
    return N; 
}
