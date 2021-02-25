using System;

namespace Invoke
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			var test = new dll();
			string str = "invoke1";
			var result = test.invoke1(ref str, 1);
			Console.WriteLine($"invoke1 result: {result}");
			str = "invoke2";
			test.invoke2(ref str);
			test.invoke3();
			str = "invoke4";
			test.invoke4(ref str);
		}
	}
}
