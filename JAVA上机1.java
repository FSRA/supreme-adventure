import java.util.*;
public class e1_ti{
    public static void main(String[]args){
        int n;
        Scanner input=new Scanner(System.in);
        n=input.nextInt();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++) System.out.print("  ");
            for(int j=i;j>=1;j--) System.out.print(j+" ");
            for(int j=2;j<=i;j++) System.out.print(j+" ");
          System.out.print("\n");
        }
    }
}

import java.util.*;
import javax.swing.*;
public class e1_t2{
    public static void main(String[]args){
        int n=Integer.parseInt(JOptionPane.showInputDialog(null,"please input i"));
        double p;
        for(int i=1;i<=n;i++){
            p+=Math.pow(-1,i+1)/(2*i-1);
     }
        p*=4;
        JOptionPane.showMessageDialog(null,p);
    }
}
import java.util.*;
public class e1_t3{
    private static boolean prime(int n){
        int ceil=(int)Math.sqrt(n);
        for(int i=2;i<=ceil;i++){
            if(n%i==0) return false;
        }
        ret
    }
    private static boolean cir(int n){
        int[]a=new int[100];
        int len=0;
        while(n>0){
            a[++len]=n%10;
            n=n/10;
        }
        for(int i=1;i<=len/2;i++)
            if(a[i]!=a[len-i+11]) return false;
        return true;
    }
    public static void main(Stirng[]args){
        int cnt=0;
        int num=2;
        int line=0;
        while(cnt<100){
            if(prime(num)&&cir(num)){
                System.out.print(num+" ");
                cnt++;
                line++;
            }
            num++;
            if(line==10){
                System.out.println();
                line=0;
            }
        }
    }
}
import java.util.*;
public class e1_t4{
    private static int n1=0,n2=0;
    public static int[]merge(int[]list1,int[]list2){
        int[]ans=new int[200];
        int i=1,j=1,k=0;
        while(i<=n1&&j<=n2){
            if(list1[i]<list2[j]){
                ans[++k]=list1[i];
                i++;
            }else{
                ans[++k]=list2[j];
                j++;
            }
          }
        while(i<=n1) ans[++k]=list1[i++];
        while(j<=n2) ans[++k]=list2[j++];
        return ans;
    }
    public static void main(String[]args){
        int[]a=new int[100];
        int[]b=new int[100];
        Scanner input=new Scanner(System.in);
        n1=input.nextInt();
        for(int i=1;i<=n1;i++)
            a[i]=input.nextInt();
        n2=input.nextInt();
        for(int i=1;i<=n2;i++)
            b[i]=input.nextInt();
        int[]ans=merge(a,b);
        for(int i=1;i<=n1+n2;i++)
            System.out.print(ans[i]+" ");
    }
}
