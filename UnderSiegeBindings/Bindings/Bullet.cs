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
	public class Bullet : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("speed"), DisplayName("Speed")]
		public float Speed { get; set; } = 0.000000f;

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("damage"), DisplayName("Damage")]
		public float Damage { get; set; } = 0.000000f;

		[Serialize, DisplayPriority(3)]
		[XmlAttribute("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[Serialize, DisplayPriority(4)]
		[XmlAttribute("bullet_prefab"), DisplayName("Bullet Prefab")]
		public Path BulletPrefab { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(5)]
		[XmlAttribute("explosion_prefab"), DisplayName("Explosion Prefab")]
		public Path ExplosionPrefab { get; set; } = new Path(@"");
	}
}
