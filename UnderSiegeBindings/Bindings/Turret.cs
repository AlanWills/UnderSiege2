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
	public class Turret : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("damage"), DisplayName("Damage")]
		public int Damage { get; set; } = 0;

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("fire_rate"), DisplayName("Fire Rate")]
		public float FireRate { get; set; } = 1.000000f;

		[Serialize, DisplayPriority(3)]
		[XmlAttribute("bullet"), DisplayName("Bullet")]
		public Path Bullet { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(4)]
		[XmlAttribute("turret_prefab"), DisplayName("Turret Prefab")]
		public Path TurretPrefab { get; set; } = new Path(@"");
	}
}
