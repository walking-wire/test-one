#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
typedef double db;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
//#include<mybigint.h>
#define U32 unsigned int
#define S32 int
#define S64 long long
#define U64 unsigned long long
//Base为基底的幂次，即b=2^Base 
#define Base 32ll			 
 
//按16进制来弄，先把10进制弄成16进制，然后逐个实现这些函数，调试就用main就好了 
//先把每个大整数数组的第一位留出来，以作备用。大整数位数单独保存。 
 
int MxLen=2; 	//MxLen表示当前所有整数里面位数最长的那个，好像和iBNWordLen是一个东西。
S32 Alt=0;		//Alt相当于BN_Reset的参数，alt==1的时候，第0位不复制。
S32 max(S32 a,S32 b); 

/*
输入一个储存10进制大数的字符数组，返回一个储存16进制大数的U32数组。 
*/ 
U32 *DEC_to_HEX(char *s); 

/*
输出num的十六进制形式，并保留前导0； 
由于直接用printf函数的%X提示符会忽略前导0，所以要多用一个函数输出。 
*/ 
void PrintHex(U32 num);	 

void BN_Print(U32 *pwBN,S32 iBNWordLen);
void BN_Reset(U32 *pwBN,S32 iBNWordLen);
void BN_Assign(U32 *pwDest, U32 *pwSource, S32  iBNWordLen);
void BN_SetInt(U32* pwX, S32 siL, U32 uiY);
S32 BN_IsZero(U32 *pwBN,S32 iBNWordLen);
S32 BN_IsOne(U32 *pwBN,S32 iBNWordLen);
S32 BN_IsEven(U32 *pwBN);
S32 BN_IsOdd(U32 *pwBN);
S32 BN_JE(U32 *pwX, U32 *pwY, S32 iBNWordLen);
S32 BN_JA(U32 *pwX, U32 *pwY, S32 iBNWordLen);
S32 BN_GetBitLen(U32 *pwBN, S32 iBNWordLen);
S32 BN_GetWordLen(U32 *pwBN, S32 iBNWordLen);
void BN_GetLen(S32 *pBitLen, S32 *pWordLen, U32 *pwBN, S32 iBNWordLen);
void BN_ShiftRightOneBit(U32 *pwBN, S32 iBNWordLen);
U32 BN_ShiftLeftOneBit(U32 *pwBN, S32 iBNWordLen);
U32 BN_Add(U32 *pwSum, U32 *pwX, U32 *pwY,S32  iBNWordLen);
U32 BN_Sub(U32 *pwDiff, U32 *pwX, U32 *pwY, S32  iBNWordLen);
void BN_Mul(U32 *pwPro, U32 *pwX, U32 *pwY, S32  iBNWordLen);
//S32 BN_Div_Basic(U32 *rem, U32 *quo, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM, S32 iBNWordLen_M);
S32 BN_Div(U32 *pwResult,  U32 *quo, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM,  S32 iBNWordLen_M);
//S32 BN_Mod_Basic(U32 *rem, S32 iBNWordLen_r, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM, S32 iBNWordLen_M);
S32 BN_Mod(U32 *pwResult, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM, S32 iBNWordLen_M);
void BN_ModWord(U32 *pwResult, U32 *pwBN, S32 iBNWordLen, U32 n);

char s1[100005],s2[100005];
S32 len,opt;
U32 *pa,*pb,ans[1000005];
U64 a[100005];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	printf("Input two big int\n");
	scanf("%s %s",s1,s2);
	pa=DEC_to_HEX(s1); 
	pb=DEC_to_HEX(s2);
	while (1)
	{
		printf("input 1 to add\ninput 2 to subtract\ninput 3 to multiply\ninput 4 to divide\ninput 5 to module\n");
		BN_Reset(ans,MxLen);
		scanf("%d",&opt);
		if (opt==1)
		{
			BN_Add(ans,pa,pb,MxLen);
		}else
		if (opt==2)
		{
			BN_Sub(ans,pa,pb,MxLen);
		}else
		if (opt==3)
		{
			BN_Mul(ans,pa,pb,MxLen);
		}else
		if (opt==4)
		{
			U32 *tmp=(U32*)calloc(100000,4);
			BN_Div(tmp,ans,pa,MxLen,pb,BN_GetWordLen(pb,MxLen));
			BN_Print(tmp,MxLen);
		}else
		{
			BN_Mod(ans,pa,MxLen,pb,BN_GetWordLen(pb,MxLen));
		}
		BN_Print(ans,MxLen);
		break;
	}
}

S32 max(S32 a,S32 b) 
{
	if (a>b) return a;
	return b;
}

U32 *DEC_to_HEX(char *s)
{
	S32 wlen=0,i;
	len=strlen(s);
	for(i=1;i<=len;i++) a[i]=s[len-i]-'0';
	a[0]=len;
	U64 tmp,t;
	U32 *ret=(U32*)calloc(100000,4);
	while (a[0])
	{
		tmp=0;
		for(i=a[0];i>=1;i--)
		{
			t=(a[i]+tmp*10)&((1ll<<Base)-1);
			a[i]=(a[i]+tmp*10)>>(Base);
			tmp=t;
		}
		ret[++wlen]=tmp;
		//printf("%X",tmp);
		while (!a[a[0]]&&a[0]) a[0]--;
	}
	//printf("\n");
	MxLen=max(MxLen,wlen);
	return ret;
}

void PrintHex(U32 num)
{
	char s[8];
	S32 i,tmp;
	for(i=0;i<Base/4;i++)
	{
		tmp=num&15;
		if (tmp<=9) 
			s[i]='0'+tmp;
		else
			s[i]='a'+tmp-10;
		num>>=4;
	}
	i=i-1;
	while (i>=0) putchar(s[i--]); 
	//putchar(' ');
}

void BN_Print(U32 *pwBN,S32 iBNWordLen)
{
	S32 i=BN_GetWordLen(pwBN,iBNWordLen);
	printf("0x");
	if (!i) putchar('0');
	else
	{
		printf("%x",pwBN[i]); 
		for(i=i-1;i;i--)
			PrintHex(pwBN[i]);
	}
	putchar('\n');
}

void BN_Reset(U32 *pwBN,S32 iBNWordLen)
{
	while (iBNWordLen>0) pwBN[iBNWordLen--]=0;
}

void BN_Assign(U32 *pwDest, U32 *pwSource, S32  iBNWordLen)
{
	for(S32 i=1;i<=iBNWordLen;i++)
		pwDest[i]=pwSource[i];
}

void BN_SetInt(U32* pwX, S32 siL, U32 uiY)
{
	BN_Reset(pwX,siL);
	pwX[1]=uiY;
}

S32 BN_IsZero(U32 *pwBN,S32 iBNWordLen)
{
	for (S32 i=1;i<=iBNWordLen;i++)
		if (pwBN[i]) 
			return 0;
	return 1;
}

S32 BN_IsOne(U32 *pwBN,S32 iBNWordLen)
{
	S32 i;
	for (i=2;i<=iBNWordLen;i++)
		if (pwBN[i]) 
			return 0;
	return (pwBN[i]==1); 
}

S32 BN_IsEven(U32 *pwBN)
{
	return !(pwBN[1]&1);
}
S32 BN_IsOdd(U32 *pwBN)
{
	return (pwBN[1]&1);
}

S32 BN_JE(U32 *pwX, U32 *pwY, S32 iBNWordLen)
{
	for(S32 i=1;i<=iBNWordLen;i++) 
		if (pwX[i]!=pwY[i])
			return (pwX[i]==pwY[i]);
	return 0;
}
S32 BN_JA(U32 *pwX, U32 *pwY, S32 iBNWordLen)
{
	for(S32 i=iBNWordLen;i;i--) 
		if (pwX[i]!=pwY[i])
			return (pwX[i]>pwY[i]);
	return 0;
}

S32 BN_GetBitLen(U32 *pwBN, S32 iBNWordLen)
{
	S32 ret=0;
	U32 tmp=pwBN[iBNWordLen];
	while (tmp) tmp>>=1,ret++;
	return ret+BN_GetWordLen(pwBN,iBNWordLen)-Base;
}

S32 BN_GetWordLen(U32 *pwBN, S32 iBNWordLen)
{
	S32 i;
	for(i=MxLen;i;i--)
		if (pwBN[i])
			break;
	return i;
} 

void BN_GetLen(S32 *pBitLen, S32 *pWordLen, U32 *pwBN, S32 iBNWordLen)
{
	(*pBitLen)=BN_GetBitLen(pwBN,iBNWordLen);
	(*pWordLen)=BN_GetWordLen(pwBN,iBNWordLen);
}

void BN_ShiftRightOneBit(U32 *pwBN, S32 iBNWordLen)
{
	for(S32 i=1;i<=iBNWordLen+1;i++)
	{
		pwBN[i]>>=1;
		pwBN[i]=(pwBN[i+1]&1)<<(Base-1);
	}
}

U32 BN_ShiftLeftOneBit(U32 *pwBN, S32 iBNWordLen)//不能每次只开够恰好mxlen位，因为这里会爆炸，当然，如果你舍弃掉最高位就没问题了 
{
	for(S32 i=iBNWordLen;i;i--)
	{
		pwBN[i]=((pwBN[i]<<1)&((1ll<<Base)-1))+((i>1)?(pwBN[i-1]>>(Base-1)):0);
	}
}

U32 BN_Add(U32 *pwSum, U32 *pwX, U32 *pwY,S32  iBNWordLen)
{
	S32 i,k=0;
	for (i=1;i<=iBNWordLen;i++)
	{
		pwSum[i]=(pwX[i]+pwY[i]+k)&((1ll<<Base)-1);
		k=((S64)pwX[i]+(S64)pwY[i]+(S64)k)>>Base;
	}
	pwSum[i]=k;
	if (k) MxLen=max(MxLen,i);
	return k;
}

U32 BN_Sub(U32 *pwDiff, U32 *pwX, U32 *pwY, S32  iBNWordLen)
{
	S32 i,k=0;
	for (i=1;i<=iBNWordLen;i++)
	{
		pwDiff[i]=(pwX[i]-pwY[i]+k);
		if (Base!=32ll&&(S32)(pwX[i]-pwY[i]+k)<0) pwDiff[i]+=1ll<<Base;
		k=-((S64)pwX[i]-((S64)pwY[i]-(S64)k)<0);
	}
	return k;
}

void BN_Mul(U32 *pwPro, U32 *pwX, U32 *pwY, S32  iBNWordLen)
{
	S32 i,j;
	U64 t;
	U32 k;
	for(i=1;i<=iBNWordLen;i++) 
	{
		if (pwX[i])
		{
			k=0;
			for (j=1;j<=iBNWordLen;j++)
			{
				t=(U64)pwX[i]*(U64)pwY[j]+pwPro[i+j-1]+k;
				pwPro[i+j-1]=t&((1ll<<Base)-1);
				k=t>>Base; 
			}
			pwPro[i+j-1]=k;
		}
	}
	i=i*2;
	while (!pwPro[i]) i--;
	MxLen=max(MxLen,i);
}
S32 BN_Div(U32 *rem, U32 *quo, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM, S32 iBNWordLen_M)
{
	S32 n=iBNWordLen_X,m=iBNWordLen_M,i,j;
	U32 *A=(U32 *)calloc(n+5,4),*B=pwBNM,*tmp=(U32 *)calloc(m+5,4),*(a[Base]);			//a/b
	BN_Assign(A,pwBNX,n);
	a[0]=B;
	for(i=1;i<=(Base-1);i++)
	{
		a[i]=(U32 *)calloc(m+5,4);
		BN_Assign(a[i],a[i-1],m+1);
		BN_ShiftLeftOneBit(a[i],m+1);
	}
	Alt=1;
	for(i=n-m+1;i>=1;i--)
	{
		for(j=(Base-1);j>=0;j--)
			if (!BN_JA(a[j],A+i-1,m+1))
			{
				BN_Reset(tmp,m+1);
				BN_Sub(tmp,A+i-1,a[j],m+1);
				BN_Assign(A+i-1,tmp,m+1);
				quo[i]|=1<<j;
			}
	}
	Alt=0;
	BN_Assign(rem,A,m+1);
	free(A);free(B);free(tmp);
	for(i=1;i<=(Base-1);i++) 
		free(a[i]);
}
S32 BN_Mod(U32 *pwResult, U32 *pwBNX, S32 iBNWordLen_X, U32 *pwBNM, S32 iBNWordLen_M)
{
	U32 *tmp=(U32 *)calloc(iBNWordLen_M+5,4);
	BN_Div(pwResult,tmp,pwBNX,iBNWordLen_X,pwBNM,iBNWordLen_M);
	free(tmp);
}
void BN_ModWord(U32 *pwResult, U32 *pwBN, S32 iBNWordLen, U32 n)
{
	U32 *tmp=(U32 *)calloc(iBNWordLen+5,4),*nn=(U32 *)calloc(iBNWordLen+5,4);
	BN_SetInt(nn,iBNWordLen,n);
	BN_Div(pwResult,tmp,pwBN,iBNWordLen,nn,1);
	free(tmp);free(nn);
}
