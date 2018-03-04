using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BindingsLib;

namespace US
{
	public class Shield : ScriptableObject
	{
		public int strength { get; set; } = 100;
		public int recharge_per_second { get; set; } = 1;
		public Texture2D texture { get; set; }
		public Vector3 colour { get; set; } = new Vector3(1.000000f, 1.000000f, 1.000000f);
	}
}
