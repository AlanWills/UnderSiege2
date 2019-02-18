using CelesteEngineEditor;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;
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

            Image image = new Image()
            {
                Source = tileMapEditor.TileMapEditorViewModel.SelectedTile.Texture.ToImageSource(),
                Width = 96,
                Height = 96
            };
            tileMapEditor.Canvas.Children.Add(image);
        }
    }
}
