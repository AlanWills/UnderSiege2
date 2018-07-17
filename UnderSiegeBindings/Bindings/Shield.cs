using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Threading.Tasks;
using System.Xml.Serialization;
using BindingsKernel;

namespace US
{
	public class Shield : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("strength"), DisplayName("Strength")]
		public int Strength { get; set; } = 100;

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("recharge_per_second"), DisplayName("Recharge Per Second")]
		public int RechargePerSecond { get; set; } = 1;

        [Serialize, DisplayPriority(3)]
        [XmlAttribute("texture"), DisplayName("Texture")]
        public Texture2D Texture { get; set; }

		[Serialize, DisplayPriority(4)]
		[XmlAttribute("colour"), DisplayName("Colour")]
		public Vector3 Colour { get; set; } = new Vector3(1.000000f, 1.000000f, 1.000000f);
	}
}
