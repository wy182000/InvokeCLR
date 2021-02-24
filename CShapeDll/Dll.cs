using System;

namespace CShapeDll
{
	public class Dll
	{
		public bool Invoke(ref string value)
		{
			Console.WriteLine($"Invoke: {value}");
			return true;
		}
	}
}
