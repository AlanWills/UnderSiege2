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
	public class Level : ScriptableObject
	{
		[DisplayPriority(1)]
		[XmlAttributeName("screen_file_path"), DisplayName("Screen File Path")]
		public Path ScreenFilePath { get; set; } = new Path(@"");

		[DisplayPriority(2)]
		[XmlAttributeName("background_file_path"), DisplayName("Background File Path")]
		public Path BackgroundFilePath { get; set; } = new Path(@"");

		[DisplayPriority(3)]
		[XmlAttributeName("player_spawn_position"), DisplayName("Player Spawn Position")]
		public Vector2 PlayerSpawnPosition { get; set; } = new Vector2(0.000000f, 0.000000f);

		[DisplayPriority(4)]
		[DisplayName("Ship Manager")]
		public ShipManager ShipManager { get; set; }
	}
}
