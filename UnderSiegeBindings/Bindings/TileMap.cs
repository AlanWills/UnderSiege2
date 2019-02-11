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
	public class TileMap : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("dimensions"), DisplayName("Dimensions")]
		public Vector2 Dimensions { get; set; } = new Vector2(0.000000f, 0.000000f);
	}
}
