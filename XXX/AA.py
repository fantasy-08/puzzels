'''
1---------
      -------
2-----
         ---------
3     =========
 =========
4 =========
              ==========
5
  ****
     ****
6 *****
      *****
7 8888888888
  8888888888

'''
import java.util.*;
 
public class temporary
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0;i<t;i++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int r = sc.nextInt();
			int mi = Math.min(a,b);
			int ma = Math.max(a,b);
			if(c>=ma)
			{
				if(c-r>ma)
				{
					System.out.println(Math.abs(ma-mi));
					continue;
				}
				else
				{
					int min = Math.max(mi,c-r);
					System.out.println(Math.abs(min - mi));
					continue;
				}
			}
			else if(c<=mi)
			{
				if(c+r<mi)
				{
					System.out.println(Math.abs(ma-mi));
					continue;
				}
				else
				{
					int max = Math.min(ma,c+r);
					System.out.println(Math.abs(ma-max));
					continue;
				}
			}
			else
			{
				int x =	Math.max(mi,c-r);
				int y =	Math.min(ma,c+r);
				System.out.println(Math.abs(x-mi) + Math.abs(ma-y));
				continue;
			}
		}
	}
}