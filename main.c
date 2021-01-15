#include <stdio.h>
#include <stdlib.h>

#define MAXWORDLENGTH 50
#define MAXWORDNUMBER 50

int main() {
	
	char dict[MAXWORDNUMBER][MAXWORDLENGTH];
	char tmp[MAXWORDLENGTH];
	int startingpositions[26];
    int i,j,k,n;
    
    for(i=0;i<26;i++)
	  startingpositions[i]=-128;
	  
	printf("Enter the number of words. #max num of words must<%d#\n",MAXWORDNUMBER);
	scanf("%d",&n);
	fflush(stdin);
	
	printf("You will be asked to enter the words to create a dictionary.\n#max length of words must<%d#\n\n",MAXWORDLENGTH);
	for(i=0;i<n;i++){
		printf("Enter the %d. word: \n",i+1);
		
		gets(tmp);
		//aldigim kelimenin harflerini upper case yapiyorum.
		//bu onemli,  kelimeleri siradiktan sonra ör. {ADANA, ZIRAAT, belcika} siralamasi olusmasini istemiyorum.
		k=0;
		while(tmp[k]!='\0'){
			if(tmp[k]>=97 && tmp[k]<=122)
			  dict[i][k]=tmp[k]-32;
			else
			  dict[i][k]=tmp[k];
			
			k++;
		}
		dict[i][k]='\0';
		//bu islem kolayca toupper fonksiyonu ile yapilabilirdi.	
	}
	
	
	//Bubble sort kullandim. ascii olarak düsük olan kelime basa gelecek.
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
	
	
	    int l=0;
	    int sonuc;
		while( ( dict[j][l] != '\0' && dict[j+1][l] != '\0' ) && dict[j][l] == dict[j+1][l] ){
          l++;
        }

       if(dict[j][l] == dict[j+1][l])
          sonuc=0; // strings are identical
        else
           sonuc= dict[j][l]-dict[j+1][l];
            
		
			
			//if (strcmp(dict[j],dict[j+1])>0){
			if(sonuc>0){
			
			    
			    //eger ilk kelime daha asagida olmasi gerekiyorsa ikinci ile yer degistiriyor.
			    k=0;
				while(dict[j][k]!='\0'){
				    tmp[k]=dict[j][k];
				    k++;
			    }
			    tmp[k]='\0';
			    
			    k=0;
				while(dict[j+1][k]!='\0'){
				    dict[j][k]=dict[j+1][k];
				    k++;
			    }
			    dict[j][k]='\0';
			  
                k=0;
				while(tmp[k]!='\0'){
				    dict[j+1][k]=tmp[k];
				    k++;
			    }
			    dict[j+1][k]='\0';
			  			  
		/*	  
			  Bu yer degistirme islemi daha basit olarak soyle yapilabilirdi.
			  strcpy(tmp,dict[j]);
			  strcpy(dict[j],dict[j+1]);
			  strcpy(dict[j+1],tmp);   */
		    }
		
		}
		
	}
	
	printf("\nSorted Dictionary\n");
	//simdi bunu yazdiralim.
	for(i=0;i<n;i++){
		int j=0;
		
		while(dict[i][j]!='\0'){
			printf("%c",dict[i][j]);
			j++;
		}
		printf("\n");
	}
	
	//burada ise, mesela 1. indiste, B harfi ile baslayan kelimeler sözlükte yer aliyorsa, bunlarin ilk satirinin numarasi yer alacak.
	for(i=n-1;i!=-1;i--){
		startingpositions[dict[i][0]-65]=i;
	}
	
	//simdi ise bu diziyi yazdiralim.
	printf("\n");
	for(i=0;i<26;i++)
	  if(startingpositions[i]!=-128)
	    printf("%c:%d\t",i+65,startingpositions[i]+1);
	  else
	    printf("%c: \t",i+65);
	
	
	
	
	
	
	
	printf("\n\nEnter the word which will be searched in dictionary.\n");
	gets(tmp);
	k=0;
	while(tmp[k]!='\0'){
		if(tmp[k]>=97 && tmp[k]<=122)
			tmp[k]=tmp[k]-32;		
		k++;
	}
		
	
	
    k=0;
    int sonindis;
	if(startingpositions[tmp[0]-65]!=-128){
	   //aranan kelimenin ilk harfi ile baslayan bir sözcük var.
	   
	   j=startingpositions[tmp[0]-65];
	  //aramaya baslanacak indis.
	  
	  i=tmp[0]-65+1;
	  while(startingpositions[i]==-128 && i<26)
	  i++;	  
	  //aramanin bitmesi gereken indisi buluyorum.
	  if(i>=26){
	  	sonindis=n;
	  }
	  else 
	   sonindis = startingpositions[i];
	
	
	  while(j< sonindis && k==0){
	   	  	     
		    
		    
		int l=0;
	    int sonuc;
		while( ( dict[j][l] != '\0' && tmp[l] != '\0' ) && dict[j][l] == tmp[l] ){
          l++;
        }

       if(dict[j][l] == tmp[l])
          sonuc=0; // strings are identical
        else
           sonuc= dict[j][l]-tmp[l];
			
			
			if(sonuc==0){
			//if(strcmp(dict[j],tmp)==0){
				printf("\n%s exists in the dictionary in %d.row\n",tmp, j+1);
				k++;
			}
	   	  	j++;
	    }
		if(k==0)
			printf("\nThe word: %s does not exist in the dictionary.\n",tmp);
	
			
	}
	else
	  printf("\n%s does not exist in the dictionary.\n",tmp);
	
	
	return 0;
}
