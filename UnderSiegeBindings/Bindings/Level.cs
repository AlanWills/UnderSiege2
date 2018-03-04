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
		public string screen_file_path { get; set; } = "";
		public string background_file_path { get; set; } = "";
		public Vector2 player_spawn_position { get; set; } = new Vector2(0.000000f, 0.000000f);
		public ShipManager ShipManager { get; set; }
	}
}
