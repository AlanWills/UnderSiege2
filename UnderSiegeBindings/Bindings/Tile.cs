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
	public class Tile : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("texture"), DisplayName("Texture")]
		public Texture2D Texture { get; set; }

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("traversable"), DisplayName("Traversable")]
		public bool Traversable { get; set; } = false;
	}
}
