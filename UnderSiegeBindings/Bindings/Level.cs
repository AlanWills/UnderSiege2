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
		[XmlAttribute("screen_path"), DisplayName("Screen Path")]
		public Path ScreenPath { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("tile_map_path"), DisplayName("Tile Map Path")]
		public Path TileMapPath { get; set; } = new Path(@"");
	}
}
