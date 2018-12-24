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
	public class Ship : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("hull_strength"), DisplayName("Hull Strength")]
		public float HullStrength { get; set; } = 0.000000f;

		[Serialize, DisplayPriority(3)]
		[XmlAttribute("shield"), DisplayName("Shield")]
		public Path Shield { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(4)]
		[XmlAttribute("ship_prefab"), DisplayName("Ship Prefab")]
		public Path ShipPrefab { get; set; } = new Path(@"");
	}
}
