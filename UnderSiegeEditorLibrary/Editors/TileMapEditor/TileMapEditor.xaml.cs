using BindingsKernel;
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

namespace UnderSiegeEngineLibrary.Editors
{
    /// <summary>
    /// Interaction logic for TileMapEditor.xaml
    /// </summary>
    [CustomEditor(typeof(TileMap), "Tile Map Editor", DockPosition.Document)]
    public partial class TileMapEditor : Editor
    {
        #region Properties and Fields

        public TileMapEditorViewModel TileMapEditorViewModel { get; private set; }

        private bool isMouseDown;
        private Point dragStart;

        #endregion

        public TileMapEditor() :
            base(new TileMapEditorViewModel())
        {
            TileMapEditorViewModel = ViewModel as TileMapEditorViewModel;

            InitializeComponent();

            Canvas.Width = ActualWidth;
            Canvas.Height = ActualHeight;

            KeyBinding kb = new KeyBinding()
            {
                Key = Key.N,
                Command = new AddTileCommand(),
                CommandParameter = this
            };

            InputBindings.Add(kb);
        }

        #region Mouse Callbacks

        private void Canvas_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            UIElement uiElement = sender as UIElement;

            isMouseDown = true;
            dragStart = Mouse.GetPosition(uiElement);
        }

        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMouseDown)
            {
                return;
            }

            UIElement uiElement = sender as UIElement;

            var now = e.GetPosition(uiElement);
            var diff = now - dragStart;
            dragStart = now;
            foreach (UIElement child in Canvas.Children)
            {
                child.RenderTransform = new TranslateTransform()
                {
                    X = child.RenderTransform.Value.OffsetX + diff.X,
                    Y = child.RenderTransform.Value.OffsetY + diff.Y
                };
            }

            Debug.Text = diff.ToString();
        }

        private void Canvas_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            isMouseDown = false;
        }

        #endregion
    }
}