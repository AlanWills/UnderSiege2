using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BindingsLib;

namespace US
{
	public class Ship : ScriptableObject
	{
		[XmlAttributeName("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[XmlAttributeName("hull_strength"), DisplayName("Hull Strength")]
		public float HullStrength { get; set; } = 0.000000f;
	}
}
