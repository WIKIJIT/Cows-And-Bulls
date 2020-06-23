#include<iostream>
using namespace std;
class CowsAndBulls
{
  int number,numar[4],i,j,digits,modech,pon,ptn,pocn[4],ptcn[4],cowso,bullso,cowst,bullst,rch;
  char ch;
  bool isGuess,isDigit,lstch,dch,visited[4];
  public:
    CowsAndBulls()
    {
      ch='y';
      i=3;
      modech=0;
      isGuess=true;
      isDigit=true;
      lstch=true;
      dch=false;
    }
    bool DigitCheck(int temp)
    {
      digits=0;
      while(temp>0)
      {
        temp=temp/10;
        digits++;
      }
      if(digits!=4)
        return true;
      else
        return false;
    }
    void GenerateNumber()
    {
      isDigit=true;
      while(isDigit)
      {
        number=rand()%9999+1000;
        isDigit=DigitCheck(number);
      }
      if(!isDigit)
      {
        i=3;
        while(number>0)
        {
          numar[i]=number%10;
          number=number/10;
          i--;
        }
      }
    }
    void check()
    {
      cowso=0;
      bullso=0;
      cowst=0;
      bullst=0;
      i=3;
      while(pon>0)
      {
        pocn[i]=pon%10;
        pon=pon/10;
        i--;
      }
      i=3;
      while(ptn)
      {
        ptcn[i]=ptn%10;
        ptn=ptn/10;
        i--;
      }
      for(i=0;i<4;i++)
      {
        visited[i]=false;
        if(numar[i]==pocn[i])
          bullso++;
      }
      for(i=0;i<4;i++)
        for(j=0;j<4;j++)
          if(numar[i]==pocn[j]&&!visited[j])
          {
            cowso++;
            visited[j]=true;
            break;
          }
      for(i=0;i<4;i++)
      {
        visited[i]=false;
        if(numar[i]==ptcn[i])
          bullst++;
      }
      for(i=0;i<4;i++)
        for(j=0;j<4;j++)
          if(numar[i]==ptcn[j]&&!visited[j])
          {
            
            cowst++;
            visited[j]=true;
            break;
          }
      lstch=false;
      if(modech==1)
      {
        cout<<"\nYour Status:\nCows: "<<cowso<<"\tAND Bulls: "<<bullso<<endl;
        cout<<"\nComputer's Status:\nCows: "<<cowst<<"\tAND Bulls: "<<bullst<<endl;
      }
      else
      {
        cout<<"\nPlayer 1's Status:\nCows: "<<cowso<<"\tAND Bulls: "<<bullso<<endl;
        cout<<"\nPlayer 2's Status:\nCows: "<<cowst<<"\tAND Bulls: "<<bullst<<endl;
      }
      if(cowso==4&&bullso==4&&cowst==4&&bullst==4)
      {
        cout<<"\nIts a draw!\n";
        cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
        cin>>rch;
        cout<<endl;
        lstch=true;
      }
      else if(modech==1&&bullso==4&&cowso==4)
      {
        cout<<"\nCongratulations you've won!\n";
        cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
        cin>>rch;
        cout<<endl;
        lstch=true;
      }
      else if(modech==1&&bullst==4&&cowst==4)
      {
        cout<<"\nYou have lost\n";
        cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
        cin>>rch;
        cout<<endl;
        lstch=true;
      }
      else if(modech==2&&bullso==4&&cowso==4)
      {
        cout<<"\nCongratulations Player 1 you've won!\n";
        cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
        cin>>rch;
        cout<<endl;
        lstch=true;
      }
      else if(modech==2&&bullst==4&&cowst==4)
      {
        cout<<"\nCongratulations Player 2 you've won!\n";
        cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
        cin>>rch;
        cout<<endl;
        lstch=true;
      }
      while(lstch)
      {
        if(dch)
        {
          cout<<"\nWould you like to:\n1. Continue in same mode\n2. Select a different mode\n3. Exit the game\nEnter (1/2/3): ";
          cin>>rch;
          cout<<endl;
        }
        switch(rch)
        {
          case 1: GenerateNumber();
                  lstch=false;
                  dch=false;
                  break;
          case 2: ch='n';
                  modech=0;
                  lstch=false;
                  dch=false;
                  break;
          case 3: ch='n';
                  dch=false;
                  lstch=false;
                  break;
          default: cout<<"\n`Worng Input! Enter again!\n";
                   dch=true;
        }
      }
    }
    void GameStart()
    {
      while(modech==0)
      {
        GenerateNumber();
        if(lstch)
          cout<<"\t\t\t\tCows AND Bulls\n\nWelcome to COWS AND BULLS!";
        cout<<"Would you like to play in:\n1. Single Player mode(versus Computer)\n2. Multi Player mode(versus Human)\nEnter your choice (1/2): ";
        cin>>modech;
        cout<<endl;
        if(modech==1)
        {
          ch='y';
          while(ch=='y')
          {
            isGuess=true;
            while(isGuess)
            {
              ptn=rand()%9999+1000;
              isGuess=DigitCheck(ptn);
            }
            cout<<"\nThe computer has guessed a number!\nNow enter your guess: ";
            isGuess=true;
            while(isGuess)
            {
              cin>>pon;
              isGuess=DigitCheck(pon);
              if(isGuess)
                cout<<"\nWrong Input! Enter again: ";
            }
            check();
          }
        }
        else if(modech==2)
        {
          ch='y';
          while(ch=='y')
          {
            cout<<"\nPlayer 1 enter your guess: ";
            isGuess=true;
            while(isGuess)
            {
              cin>>pon;
              isGuess=DigitCheck(pon);
              if(isGuess)
                cout<<"\nWrong Input! Enter again: ";
            }
            cout<<"\nPlayer 2 enter your guess: ";
            isGuess=true;
            while(isGuess)
            {
              cin>>ptn;
              isGuess=DigitCheck(ptn);
              if(isGuess)
                cout<<"\nWrong Input! Enter again: ";
            }
            check();
          }
        }
        else
        {
          cout<<"\nWrong Input!\n";
          modech=0;
        }
      }
    }
  ~CowsAndBulls(){}
};
int main()
{
  CowsAndBulls p;
  p.GameStart();
  return 0;
}
