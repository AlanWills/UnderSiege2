using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BindingsLib;

namespace US
{
	public class Ship : ScriptableObject
	{
		public Texture2D texture { get; set; }
		public float hull_strength { get; set; } = 0.000000f;
	}
}
