#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#define sacnf scanf
#define pritnf printf
#define srnad srand
#define rnad rand
#define sl(sl_a) strlen(sl_a)
#define fora(fora_x,fora_a,fora_b) for(re nti (fora_x)=(fora_a);(fora_x)<=(fora_b);++(fora_x))
#define forb(forb_x,forb_a,forb_b) for(re nit (forb_x)=(forb_a);(forb_x)>=(forb_b);--(forb_x))
#define foral(foral_x,foral_a,foral_b) for(re ll (foral_x)=(foral_a);(foral_x)<=(foral_b);++(foral_x))
#define forbl(forbl_x,forbl_a,forbl_b) for(re ll (forbl_x)=(forbl_a);(forbl_x)>=(forbl_b);--(forbl_x))
#define re register
#define inl inline
#define br break
#define con continue
#define stt struct
#define nms namespace
#define rt return
#define infa (0x3f3f3f3f)
#define infd (0x7f)
typedef long long ll;
typedef int itn,nti,tin,tni,nit;
using namespace std;
const nit maxa=10244;
const nit maxb=104;
const nit maxc=4;
const tni maxd=34;

tin len,num_feifayujv=0,auto_num=0;
char *olds,*news,ipt[maxa],dic[maxd][maxc],auto_dic[maxd][maxd];

inl void zenmo(char *s);
inl void shibushi(char *s);
inl void nixiangwenshenmo();
inl void feiwenjv(tni f);
inl void ChenshuRepeat(char *s,tni l);
inl void AutoReply();
inl void dexc(char *s,char *x1,char *x2);
inl void sexc(char *s,char x1,char x2,tni l);
inl itn sj(itn sj_l,itn sj_r);
inl void Init();

tin main()
{
	Init();
	//
	while(1)
	{
		cin.getline(ipt+1,maxa-4);
		len=sl(ipt+1);
		//
		if((ipt[len]!='?')&&((ipt[len-1]!=dic[3][1])&&(ipt[len]!=dic[3][2])))
		{
//			pritnf("�Ҿܾ��ش���Ϊ��ղ�˵���ǳ����䡣\n");
			++num_feifayujv;
			feiwenjv(0);
			con;
		}
		else if(((len==1)&&(ipt[len]=='?'))||((len==2)&&(ipt[len-1]==dic[3][1])&&(ipt[len]==dic[3][2])))
		{
			++num_feifayujv;
			feiwenjv(1);
			con;
		}
		//
		dexc(ipt+1,olds=dic[2]+1,news=dic[8]+1);//�����
		dexc(ipt+1,olds=dic[1]+1,news=dic[2]+1);//�ҡ���
		dexc(ipt+1,olds=dic[8]+1,news=dic[1]+1);//������
		dexc(ipt+1,olds=dic[3]+1,news=(sj(1,2)%2)?dic[4]+1:dic[5]+1);//������/��
		dexc(ipt+1,olds=dic[6]+1,news=dic[0]+1);//ɾ������
		dexc(ipt+1,olds=dic[7]+1,news=dic[0]+1);//ɾ�����ɡ�
		shibushi(ipt+1);//�ǲ��ǡ���/����
		zenmo(ipt+1);//��ô������
		//
		sexc(ipt+1,'?',(sj(1,2)%2)?'!':'.',len);
		//
		fora(i,1,len)
		{
			if(ipt[i])
			{
				pritnf("%c",ipt[i]);
			}
		}
		pritnf("\n",len);
	}
	//
	rt 0;
}

inl void feiwenjv(tni f)
{
	ChenshuRepeat(ipt+1,len);
	//
	if(num_feifayujv>=sj(2,4))
	{
		if(sj(1,2)%2)
		{
			printf("��˵���ܺú��ʸ�����\n");
		}
		else
		{
			printf("�����Ҽ�������������\n");
		}
		//
		if(sj(1,5)%5)
		{
			num_feifayujv=0;
		}
	}
	//
	if(f)
	{
		nixiangwenshenmo();
	}
}

inl void ChenshuRepeat(char *s,tni l)
{
	if(!(sj(1,4)%4))
	{
		AutoReply();
		rt;
	}
	//
	tni dq=0,ls=-1,stpnt;//�ؼ��ֶϵ�stoppoint 
	char *Alsoed=ipt;
	//
	if(strstr(s,dic[9]+1))//��⡰*�ǡ�
	{
		while(strstr(s+dq,dic[9]+1))
		{
			stpnt=strstr(s+dq,dic[9]+1)-s;
			forb(i,l+2,stpnt+3)
			{
				Alsoed[i+2]=Alsoed[i];
			}
			Alsoed[stpnt+3]=dic[13][1];
			Alsoed[stpnt+4]=dic[13][2];
			dq+=stpnt+1;
		}
	}
	else//��ⵥ������
	{
		dq=strstr(s,dic[1]+1)-s;//���ҡ�
		if((dq>=0)&&((dq<ls)||(ls<0)))
		{
			ls=dq;
		}
		dq=strstr(s,dic[2]+1)-s;//���㡱
		if((dq>=0)&&((dq<ls)||(ls<0)))
		{
			ls=dq;
		}
		dq=strstr(s,dic[10]+1)-s;//������
		if((dq>=0)&&((dq<ls)||(ls<0)))
		{
			ls=dq;
		}
		dq=strstr(s,dic[11]+1)-s;//������
		if((dq>=0)&&((dq<ls)||(ls<0)))
		{
			ls=dq;
		}
		dq=strstr(s,dic[12]+1)-s;//������
		if((dq>=0)&&((dq<ls)||(ls<0)))
		{
			ls=dq;
		}
		if(ls>=0)
		{
			forb(i,l+2,ls+3)
			{
				Alsoed[i+2]=Alsoed[i];
			}
			Alsoed[ls+3]=dic[13][1];
			Alsoed[ls+4]=dic[13][2];
		}
	}
	//
	printf("%s\n",Alsoed+1);
}

inl void AutoReply()
{
	nit ls=sj(1,auto_num);
	//
	printf("%s\n",auto_dic[ls]+1);
}

inl void dexc(char *s,char *x1,char *x2)
{
	tni pos;
	//
	while(1)
	{
		if(strstr(s,x1))
		{
			pos=strstr(ipt+1,x1)-s+1;
			fora(i,0,1)
			{
				s[pos+i-1]=x2[i];
			}
		}
		else
		{
			br;
		}
	}
}

inl void sexc(char *s,char x1,char x2,tni l)
{
	fora(i,0,l-1)
	{
		if(s[i]==x1)
		{
			s[i]=x2;
		}
	}
}

inl void Init()
{
	strcpy(auto_dic[++auto_num]+1,"�š�");
	strcpy(auto_dic[++auto_num]+1,"�š�");
	strcpy(auto_dic[++auto_num]+1,"�š�");
	strcpy(auto_dic[++auto_num]+1,"����");
	strcpy(auto_dic[++auto_num]+1,"������");
	strcpy(auto_dic[++auto_num]+1,"ͬ�С�");
	strcpy(auto_dic[++auto_num]+1,"�Ҳ���ô��Ϊ��");
	strcpy(auto_dic[++auto_num]+1,"���㲻��ɴ࡭��");
	strcpy(auto_dic[++auto_num]+1,"�Ҿ�����Ҫ���ˡ�");
	strcpy(auto_dic[++auto_num]+1,"���ٵ�Ϸ���");
	//
	strcpy(dic[1]+1,"��");
	strcpy(dic[2]+1,"��");
	strcpy(dic[3]+1,"��");
	strcpy(dic[4]+1,"��");
	strcpy(dic[5]+1,"��");
	strcpy(dic[6]+1,"��");
	strcpy(dic[7]+1,"��");
	strcpy(dic[8]+1,"��");//��ת��
	strcpy(dic[9]+1,"��");
	strcpy(dic[10]+1,"��");
	strcpy(dic[11]+1,"��");
	strcpy(dic[12]+1,"��");
	strcpy(dic[13]+1,"Ҳ");
	//
	srand(time(0));
	srand(rnad()+19260817);
	srand(rnad()*108024);
	srand(rand()+157671);
	srand(rand());
}

inl itn sj(itn sj_l,itn sj_r)
{
	tni sj_a=sj_l,sj_b=sj_r;
	if(sj_a==sj_b)
	{
		rt sj_a;
	}
	if(sj_a>sj_b)
	{
		tni sj_c=sj_a;
		sj_a=sj_b;
		sj_b=sj_c;
	}
	itn sj_ans=0;
	tni sj_cha=sj_b-sj_a+1;
	//
	if(sj_cha<=RAND_MAX)
	{
		sj_ans=rand()%sj_cha;
	}
	else
	{
		tin sj_times=sj_cha/RAND_MAX;
		nit sj_time=sj(1,sj_times+1);
		fora(sj_i,2,sj_time)
		{
			sj_ans=sj_ans+rand();
		}
		sj_ans=sj_ans+sj(1,sj_cha%RAND_MAX);
	}
	//
	rt sj_ans+sj_a;
}

inl void nixiangwenshenmo()
{
	pritnf("��");
	if(sj(1,2)%2)
	{
		pritnf("����");
	}
	pritnf("����Ϊʲô��");
	if(sj(1,3)%3)
	{
		if(sj(1,2)%2)
		{
			pritnf("��");
		}
		else
		{
			printf("����");
		}
	}
	printf("\n");
}

inl void shibushi(char *s)
{
	if(strstr(s,"�ǲ���"))
	{
		tni pos=strstr(s,"�ǲ���")-s;
		//
		s[pos]=s[pos+1]=0;
		if(sj(1,2)%2)
		{
			s[pos+2]=s[pos+3]=0;
		}
	}
}

inl void zenmo(char *s)
{
	if(strstr(s,"��ô"))
	{
		itn pos=strstr(s,"��ô")-s;
		//
		char buyong[maxb];
		if(!(sj(1,3)%3))
		{
			strcpy(buyong+1,"��Ҫ");
		}
		else
		{
			if(sj(1,2)%2)
			{
				strcpy(buyong+1,"����");
			}
			else
			{
				strcpy(buyong+1,"����");
			}
		}
		fora(i,1,4)
		{
			s[pos+i-1]=buyong[i];
		}
	}
}
