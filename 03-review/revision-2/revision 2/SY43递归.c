int findf(int n)
{
 int s;
 if(n<=0) s=1;
 else
 {
  if(n%2==0) s=n*findf(n-1);
  else s=(n+1)-findf(n-2);
 }
 return s;
}