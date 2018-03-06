using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BindingsLib;

namespace US
{
	public class Level : ScriptableObject
	{
		[XmlAttributeName("screen_file_path"), DisplayName("Screen File Path")]
		public Path ScreenFilePath { get; set; } = new Path("");

		[XmlAttributeName("background_file_path"), DisplayName("Background File Path")]
		public Path BackgroundFilePath { get; set; } = new Path("");

		[XmlAttributeName("player_spawn_position"), DisplayName("Player Spawn Position")]
		public Vector2 PlayerSpawnPosition { get; set; } = new Vector2(0.000000f, 0.000000f);

		[DisplayName("Ship Manager")]
		public ShipManager ShipManager { get; set; }
	}
}
