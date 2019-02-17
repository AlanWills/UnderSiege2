using CelesteEngineEditor.Attributes;
using CelesteEngineEditor.Editors;
using DevZest.Windows.Docking;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using US;

namespace UnderSiegeEngineLibrary.Editors.TileMapEditor
{
    /// <summary>
    /// Interaction logic for TileMapEditor.xaml
    /// </summary>
    [CustomEditor(typeof(TileMap), "Tile Map Editor", DockPosition.Document)]
    public partial class TileMapEditor : Editor
    {
        public TileMapEditor() :
            base(new TileMapEditorViewModel())
        {
            InitializeComponent();
        }
    }
}
