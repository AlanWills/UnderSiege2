using BindingsKernel;
using CelesteEngineEditor;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace UnderSiegeEngineLibrary.Editors
{
    public class AddTileCommand : ICommand
    {
        #region Properties and Fields

        public event EventHandler CanExecuteChanged;
        
        #endregion
        
        public bool CanExecute(object parameter)
        {
            return (parameter as TileMapEditor).TileMapEditorViewModel.SelectedTile != null;
        }

        public void Execute(object parameter)
        {
            TileMapEditor tileMapEditor = parameter as TileMapEditor;

            UnsignedIntVector2 tileDimensions = tileMapEditor.TileMapEditorViewModel.TileMap.TileDimensions;
            Image image = new Image()
            {
                Source = tileMapEditor.TileMapEditorViewModel.SelectedTile.Texture.ToImageSource(),
                Width = tileDimensions.X,
                Height = tileDimensions.Y,
                RenderTransformOrigin = new Point(tileDimensions.X * 0.5, tileDimensions.Y * 0.5)
            };

            Point point = Mouse.GetPosition(tileMapEditor.Canvas);
            image.RenderTransform = new TranslateTransform(point.X, point.Y);
            tileMapEditor.Canvas.Children.Add(image);
        }
    }
}
