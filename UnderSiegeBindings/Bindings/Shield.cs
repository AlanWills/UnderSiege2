using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Threading.Tasks;
using BindingsKernel;

namespace US
{
	public class Shield : ScriptableObject
	{
		[DisplayPriority(1)]
		[XmlAttributeName("strength"), DisplayName("Strength")]
		public int Strength { get; set; } = 100;

		[DisplayPriority(2)]
		[XmlAttributeName("recharge_per_second"), DisplayName("Recharge Per Second")]
		public int RechargePerSecond { get; set; } = 1;

		[DisplayPriority(3)]
		[XmlAttributeName("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[DisplayPriority(4)]
		[XmlAttributeName("colour"), DisplayName("Colour")]
		public Vector3 Colour { get; set; } = new Vector3(1.000000f, 1.000000f, 1.000000f);
	}
}
