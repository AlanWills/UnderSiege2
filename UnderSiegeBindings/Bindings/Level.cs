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
		public string ScreenFilePath { get; set; } = "";

		[XmlAttributeName("background_file_path"), DisplayName("Background File Path")]
		public string BackgroundFilePath { get; set; } = "";

		[XmlAttributeName("player_spawn_position"), DisplayName("Player Spawn Position")]
		public Vector2 PlayerSpawnPosition { get; set; } = new Vector2(0.000000f, 0.000000f);

		public ShipManager ShipManager { get; set; }
	}
}
