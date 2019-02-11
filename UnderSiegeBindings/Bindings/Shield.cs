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
		public float Strength { get; set; } = 100.000000f;

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("recharge_per_second"), DisplayName("Recharge Per Second")]
		public float RechargePerSecond { get; set; } = 1.000000f;

		[Serialize, DisplayPriority(3)]
		[XmlAttribute("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[Serialize, DisplayPriority(4)]
		[XmlAttribute("colour"), DisplayName("Colour")]
		public Vector3 Colour { get; set; } = new Vector3(1.000000f, 1.000000f, 1.000000f);

		[Serialize, DisplayPriority(5)]
		[XmlAttribute("shield_prefab"), DisplayName("Shield Prefab")]
		public Path ShieldPrefab { get; set; } = new Path(@"");
	}
}
