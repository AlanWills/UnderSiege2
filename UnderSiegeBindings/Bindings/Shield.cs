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
		[XmlAttributeName("strength"), DisplayName("Strength")]
		public int Strength { get; set; } = 100;

		[XmlAttributeName("recharge_per_second"), DisplayName("Recharge Per Second")]
		public int RechargePerSecond { get; set; } = 1;

		[XmlAttributeName("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[XmlAttributeName("colour"), DisplayName("Colour")]
		public Vector3 Colour { get; set; } = new Vector3(1.000000f, 1.000000f, 1.000000f);
	}
}
