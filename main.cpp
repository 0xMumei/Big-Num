#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;



class TBigNum {
public:
	TBigNum(){
		pf_a = (unsigned char*)malloc(8);
		Size = 8;
		for (int i = 0; i < Size; i++) {
			pf_a[i] = 0;
		}
		Neg=false;
	}; //Default constructor


	//-----------SetSize
	void SetSize(unsigned int size)	{
		if (size != 0) {
			pf_a = (unsigned char*)malloc(size);
			Size = size;
			for (int i = 0; i < Size; i++) {
				pf_a[i] = 0;
			}
		}
		else
		{
			pf_a = (unsigned char*)malloc(8);
			Size = 8;
			for (int i = 0; i < Size; i++) {
				pf_a[i] = 0;
			}
		}
	} //Function setting size of array in memory

	//----------SetNum Functions
	void SetNum(int value){
        SetSize(sizeof(int));
		if (value < 0){
			//pf_a[Size-1] |= 1;
			value *=-1;
			Neg = true;
		}

		for (int i = 0; i < sizeof(int); i++){
			for (int j = 7; j > -1; j--){
				if (value%2 == 1) pf_a[i] |= (1 << j);
				value /= 2;
			}
		}
	}

	void SetNum(short value){
        SetSize(sizeof(short));
		if (value < 0){
			//pf_a[Size-1] |= 1;
			value *=-1;
			Neg = true;
		}

		for (int i = 0; i < sizeof(short); i++){
			for (int j = 7; j > -1; j--){
				if (value%2 == 1) pf_a[i] |= (1 << j);
				value /= 2;
			}
		}
	}

	void SetNum(long value){
        SetSize(sizeof(long));
		if (value < 0){
			//pf_a[Size-1] |= 1;
			value *=-1;
			Neg = true;
		}

		for (int i = 0; i < sizeof(long); i++){
			for (int j = 7; j > -1; j--){
				if (value%2 == 1) pf_a[i] |= (1 << j);
				value /= 2;
			}
		}
	}

    void SetNum(long long value){
        SetSize(sizeof(long long));
		if (value < 0){
			//pf_a[Size-1] |= 1;
			value *=-1;
			Neg = true;
		}

		for (int i = 0; i < sizeof(long long); i++){
			for (int j = 7; j > -1; j--){
				if (value%2 == 1) pf_a[i] |= (1 << j);
				value /= 2;
			}
		}
	}


	//------------Other functions

	void BigNumPrint(){
        /*
        cout << "Bit representation:" << endl; 
	    for (int i = 0; i < Size; i++)
	    {
	    	for (int j = 0; j < 8; j++)
	        if ((pf_a[i] << j) & 0x80) cout << 1;  //0x80 = 128
	        else cout << 0;
	    }
        cout << endl;
        */
	    long long sum = 0;

	    for (int i = 0; i < Size; i++)
	    {
	    	for (int j = 0; j < 8; j++)
	        if ((pf_a[i] << j) & 0x80)
	        	sum += pow(2, (j+i*8));
	    }
	    cout << "Value = ";
        if (Neg == true)
                cout << "-";
        cout << sum << endl;
	}//Print to screen

    void HexPrint(){
            cout << "in hex: 0x";
            long long sum_left=0, sum_right=0;
            int empty_size = Size;
            for (int i = Size; i > -1; i--)
            {   
                if (pf_a[i] != 0 && empty_size == Size){    
                    empty_size = i;
                    for(int j = 0; j < 4; j++){
                            if ((pf_a[i] << j) & 0x80){  //0x80 = 128
                            sum_right += pow(2, (j)); 
                            }
                            if ((pf_a[i] << j+4) & 0x80){  //0x80 = 128
                            sum_left += pow(2, (j)); 
                            }
                    }
                    //cout << "val in sum_left = " << sum_left << endl;
                    //cout << "val in sum_right = " << sum_right << endl;
                        switch (sum_left){
                            default : cout << sum_left; break;
                            case 0  : break;
                            case 10 : cout << "A"; break;
                            case 11 : cout << "B"; break;
                            case 12 : cout << "C"; break;
                            case 13 : cout << "D"; break;
                            case 14 : cout << "E"; break;
                            case 15 : cout << "F"; break;
                            }
                        switch (sum_right){
                            default : cout << sum_right; break;
                            case 10 : cout << "A"; break;
                            case 11 : cout << "B"; break;
                            case 12 : cout << "C"; break;
                            case 13 : cout << "D"; break;
                            case 14 : cout << "E"; break;
                            case 15 : cout << "F"; break;
                            }
                    sum_right = 0;
                    sum_left = 0;
                }else if(i < empty_size && empty_size != Size){
                         for(int j = 0; j < 4; j++){
                            if ((pf_a[i] << j) & 0x80){  //0x80 = 128
                            sum_right += pow(2, (j)); 
                            }
                            if ((pf_a[i] << j+4) & 0x80){  //0x80 = 128
                            sum_left += pow(2, (j)); 
                            }
                    }
                    //cout << "val in sum_left = " << sum_left << endl;
                    //cout << "val in sum_right = " << sum_right << endl;
                        switch (sum_left){
                            default : cout << sum_left; break;
                            case 10 : cout << "A"; break;
                            case 11 : cout << "B"; break;
                            case 12 : cout << "C"; break;
                            case 13 : cout << "D"; break;
                            case 14 : cout << "E"; break;
                            case 15 : cout << "F"; break;
                            }
                        switch (sum_right){
                            default : cout << sum_right; break;
                            case 10 : cout << "A"; break;
                            case 11 : cout << "B"; break;
                            case 12 : cout << "C"; break;
                            case 13 : cout << "D"; break;
                            case 14 : cout << "E"; break;
                            case 15 : cout << "F"; break;
                            }
                    sum_right = 0;
                    sum_left = 0;
                }
            }
        cout << endl;
    }

	int getSize(){
	return Size;
	}//Getting atribute Size

	bool getNeg(){
	return Neg;
	}//Getting atribute Neg

	unsigned char* getNum() {
                           
		unsigned char*  num = (unsigned char*)malloc(Size);
		for (int i = 0; i < Size; i++) {
			num[i] = pf_a[i];
		}
		return num;
	}//Getting full copy of num

	void operator = (unsigned char* num) {
		unsigned char* summ = (unsigned char*)malloc(Size);
		for (int i = 0; i < Size; i++) {
			summ[i] = num[i];
		}
		free(num);
		this->SetSize(Size);
		this->pf_a = summ;
	}//Overload equal 

	void BitFlip(){
		for (int i = 0; i < Size; i++) {
			pf_a[i] = ~pf_a[i];
		}
		pf_a[Size-1] |= 1;
	}//Flip all bits in function

	//------------Constructor
	
    TBigNum(unsigned int size){
		if (size != 0) {
				pf_a = (unsigned char*)malloc(size);
				Size = size;
				for (int i = 0; i < size; i++) {
					pf_a[i] = 0;
				}
			}
			else
			{
				pf_a = (unsigned char*)malloc(4);
				Size = 8;
				for (int i = 0; i < Size; i++) {
					pf_a[i] = 0;
				}
			}
		Neg=false;
	};

	//------------Destructor
	~TBigNum()
	{
		if (pf_a != NULL) {
			pf_a = (unsigned char*)malloc(Size);
			free(pf_a);
			pf_a = NULL;
		}
	}

private:
	unsigned char* pf_a;
	int Size;
	bool Neg;

};

//----------Sum Function

unsigned char* sum(const unsigned char num1[], const  unsigned char num2[], unsigned char* res, int* Size) {
	//printf("Sum started \n");
	int add = 0;
	int i = 0;
	int Byte = 8;
	int size = *Size;
	//printf("Size =  %i \n", size);
	while (i < size) {
	if (i == size)
		Byte=7;
	for (int j = 0; j < Byte; j++){
        //cout << "add : " << add << endl; 
		if ((((num1[i] << j) & 0x80) == false) && (((num2[i] << j) & 0x80) == false)) { // 0 0
			if (add == 1) {
				res[i] |= (1 << 7-j);
				add = 0;
			}
			else{
				add = 0;
			}
		//printf(" 00 step - %i, %i, add = %i \n",i,j, add);
		}
		else if ( ((((num1[i] << j) & 0x80) == false) && (((num2[i] << j) & 0x80) != false)) || ((((num1[i] << j) & 0x80) != false) && (((num2[i] << j) & 0x80) == false))) { // 0 1 | 1 0
			if (add == 1) {
				add = 1;
			}
			else {
				res[i] |= (1 << 7-j);
			}
		//printf(" 01 step - %i, %i, add = %i \n",i,j, add);
		}
		else if ((((num1[i] << j) & 0x80) != false) && (((num2[i] << j) & 0x80) != false)) { // 1 1
			if (add == 1) {
				res[i] |= (1 << 7-j);
				add = 1;
			}
			else {
				add = 1;
			}
		//printf(" 11 step - %i, %i, add = %i \n",i,j, add);
		}

    if (i == size && add == 1){
    	printf("Overflow! \n");
        unsigned char* temp = (unsigned char*)malloc(8+1);
			for (int i = 0; i < 8; i++) {
				temp[i] = res[i];
			}
			for (int j = 0; j < 8; j++) {
				temp[9] |= (1 << 7-j);
			}
			if ((((((num1[i] << 7) & 0x80) == false) && (((num2[i] << 7) & 0x80) != false)) || ((((num1[i] << 7) & 0x80) != false) && (((num2[i] << 7) & 0x80) == false)) ||((((num1[i] << 7) & 0x80) != false) && (((num2[i] << 7) & 0x80) != false))) && add == 1) {
				temp[9] |= 1;
			}
			res = NULL;
			res = temp;
			*Size = *Size + 1;
			break;
		}
	}
	i++;
	}
    /*
	printf("What in res?\n");
    for (int i = 0; i < size+1; i++)
    {
    	for (int j = 0; j < 8; j++)
        if ((res[i] << j) & 0x80) cout << 1;  //0x80 = 128
        else cout << 0;
    	puts("");
    }
    */
	return res;
}

unsigned char* operator + (TBigNum Bn1, TBigNum Bn2) {

	unsigned char* num1 = Bn1.getNum();
    unsigned char* num_temp1 = (unsigned char*)malloc(Bn1.getSize());
        for (int i = 0; i < Bn1.getSize(); i++){
            num_temp1[i] = 0;
        }
	unsigned char* num2 = Bn2.getNum();
    unsigned char* num_temp2 = (unsigned char*)malloc(Bn2.getSize());
        for (int i = 0; i < Bn2.getSize(); i++){
            num_temp2[i] = 0;
        }
	unsigned char* onenum = (unsigned char*)malloc(1);
        for (int i = 0; i < 1; i++) {
                onenum[i] = 0;
            }
	onenum[0] |= (1 << 7);//Set 1st bit to 1

	int size;

	if(Bn1.getSize() > Bn2.getSize())
		size = Bn1.getSize();
	else
		size = Bn2.getSize();

	if(Bn1.getNeg() == true){
		for (int i = 0; i < Bn1.getSize(); i++) {
			num1[i] = ~num1[i];
		}
		num_temp1 = sum(num1,onenum,num_temp1,&size);

        num1=num_temp1;
	}

	if(Bn2.getNeg() == true){
		for (int i = 0; i < Bn2.getSize(); i++) {
			num2[i] = ~num2[i];
		}
        num_temp2 = sum(num2,onenum,num_temp2,&size);
        
        num2=num_temp2;
	}

	unsigned char* num = (unsigned char*)malloc(size);
	for (int i = 0; i <= size; i++) {
		num[i] = 0;
	}

	num = sum(num1,num2,num,&size);

	return num;
	
    free(num1);
    free(num2);
}

int main() {

	TBigNum a;
	TBigNum b;
	TBigNum c(8);
	long long k=0xffffffff,j=-54400000000;
	a.SetNum(k);
	//a.BitFlip();
	b.SetNum(j);
    cout << "a : ";
	a.BigNumPrint();
    cout << "b : "; 
	b.BigNumPrint();
    cout << "a + b = c" << endl;
	c = a + b; 
	//c.BigNumPrint();
    cout << "Value of c ";
    c.HexPrint();

	return 0;
}
