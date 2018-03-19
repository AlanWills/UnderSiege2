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
	public class Ship : ScriptableObject
	{
		[DisplayPriority(1)]
		[XmlAttributeName("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[DisplayPriority(2)]
		[XmlAttributeName("hull_strength"), DisplayName("Hull Strength")]
		public float HullStrength { get; set; } = 0.000000f;
	}
}
