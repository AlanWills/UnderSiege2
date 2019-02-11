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
	public class Level : ScriptableObject
	{
		[Serialize, DisplayPriority(1)]
		[XmlAttribute("screen"), DisplayName("Screen")]
		public Path Screen { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("tile_map"), DisplayName("Tile Map")]
		public Path TileMap { get; set; } = new Path(@"");
	}
}
