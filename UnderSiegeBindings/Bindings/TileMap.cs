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
		[XmlAttribute("tile_prefab_path"), DisplayName("Tile Prefab Path")]
		public Path TilePrefabPath { get; set; } = new Path(@"");

		[Serialize, DisplayPriority(2)]
		[XmlAttribute("tile_dimensions"), DisplayName("Tile Dimensions")]
		public UnsignedVector2 TileDimensions { get; set; } = new UnsignedVector2(0, 0);
	}
}
