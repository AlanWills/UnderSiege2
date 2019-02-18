﻿using CelesteEngineEditor;
using CelesteEngineEditor.Assets;
using CelesteEngineEditor.Core;
using CelesteEngineEditor.Editors;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using US;

namespace UnderSiegeEngineLibrary.Editors
{
    public class TileMapEditorViewModel : EditorViewModel
    {
        #region Properties and Fields

        public ObservableCollection<Tile> Tiles { get; private set; } = new ObservableCollection<Tile>();

        private Tile selectedTile;
        public Tile SelectedTile
        {
            get { return selectedTile; }
            set
            {
                selectedTile = value;
                SelectedTilePreview = selectedTile.Texture.ToImageSource();

                NotifyOnPropertyChanged(nameof(SelectedTile));
            }
        }

        private ImageSource selectedTilePreview;
        public ImageSource SelectedTilePreview
        {
            get { return selectedTilePreview; }
            set
            {
                selectedTilePreview = value;
                NotifyOnPropertyChanged(nameof(SelectedTilePreview));
            }
        }
        
        #endregion

        public TileMapEditorViewModel()
        {
            foreach (Tile asset in Project.Current.FindAssets<Tile>())
            {
                Tiles.Add(asset);
            }

            SelectedTile = Tiles.FirstOrDefault();
        }
    }
}