using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace levantar_imagen
{
    public partial class Form1 : Form
    {
        String fileLoc = "";
        String exePath = "";
        String relativeFileLoc = "";
            
        public Form1()
        {
            InitializeComponent();
            NotifyIcon _icono = new NotifyIcon();
        }

        #region MENU - BOTONES

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            //openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "BMP (*.bmp)|*bmp|JPG (*.jpg)|*jpg|PNG (*.png)|*.png|GIF (*.gif)|*.gif";
            //openFileDialog1.FilterIndex = 2;          // Valor de filtro por defecto
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            //      Si levante el archivo
                            pictureBox1.ImageLocation = openFileDialog1.FileNames[0].ToString();
                            fileLoc = openFileDialog1.FileName;
                            //if (!fileLoc.Equals("") && !exePath.Equals(""))
                            if (!fileLoc.Equals("") && !exePath.Equals(""))
                                relativeFileLoc = GetRelativeFilename(exePath, fileLoc);
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: No se puede leer el archivo del disco. Original error: " + ex.Message);
                }
            }
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {

            Stream myStream;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog(); 
            //myStream = save_file.FileName;

            saveFileDialog1.Filter = "XML (*.xml)|*.xml";
            //saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog1.OpenFile()) != null)
                {
                    //StreamWriter wText = new StreamWriter(myStream);

                    //wText.Write(" your text");

                    //myStream.Close();

                    guardarXML(myStream);
                    myStream.Close();
                }
            }
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            base.Close();                   //  Cierro programa
        }

        #endregion

        #region Click en Imagen
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (pictureBox1.ImageLocation != null)
            {
                Bitmap _bit = new Bitmap(pictureBox1.ImageLocation);
                //label1.ForeColor = _bit.GetPixel(((System.Windows.Forms.MouseEventArgs)(e)).X, ((System.Windows.Forms.MouseEventArgs)(e)).Y);
                color_click.BackColor = _bit.GetPixel(((System.Windows.Forms.MouseEventArgs)(e)).X, ((System.Windows.Forms.MouseEventArgs)(e)).Y);
                guardarToolStripMenuItem.Enabled=true;
            }
        }
        #endregion

        private void guardarXML(Stream myStream)
        {
            System.Xml.XmlDocument doc = new System.Xml.XmlDocument();
            //System.Xml.XmlAttribute atributo;

            System.Xml.XmlDeclaration declaration = doc.CreateXmlDeclaration("1.0", "UTF-8", "");
            doc.AppendChild(declaration);

            System.Xml.XmlNode pmml = doc.CreateElement("PMML");
            /*
            atributo = doc.CreateAttribute("version");
            atributo.InnerText = "3.0";
            pmml.Attributes.Append(atributo);
            atributo = doc.CreateAttribute("xmlns");
            atributo.InnerText = "http://www.dmg.org/PMML-3-0";
            pmml.Attributes.Append(atributo);
            atributo = doc.CreateAttribute("xmlns:xsi");
            atributo.InnerText = "http://www.w3.org/2001/XMLSchema_instance";
            pmml.Attributes.Append(atributo);
              */

            pmml.Attributes.Append(setAtributo(doc, "version", "3.0"));
            pmml.Attributes.Append(setAtributo(doc, "xmlns", "http://www.dmg.org/PMML-3-0"));
            pmml.Attributes.Append(setAtributo(doc, "xmlns:xsi", "http://www.w3.org/2001/XMLSchema_instance"));
            doc.AppendChild(pmml);

            System.Xml.XmlNode sprite = doc.CreateElement("TEXTURA");
            if (textureName.Text.Equals(""))
                sprite.Attributes.Append(setAtributo(doc,"Name","none"));
            else
                sprite.Attributes.Append(setAtributo(doc, "Name", textureName.Text));

            if (useRelativePath.Checked && !relativeFileLoc.Equals(""))
                sprite.Attributes.Append(setAtributo(doc, "TextureFile", relativeFileLoc.Insert(0,"..\\").Replace('\\','/')));
            else
                sprite.Attributes.Append(setAtributo(doc, "TextureFile", fileLoc));

            int colorR = color_click.BackColor.R;
            int colorG = color_click.BackColor.G;
            int colorB = color_click.BackColor.B;
            //sprite.Attributes.Append(setAtributo(doc, "ColorKey", "FF"+R+G+B));
            System.Xml.XmlNode colorKey = doc.CreateElement("ColorKey");
            colorKey.Attributes.Append(setAtributo(doc, "R", colorR.ToString()));
            colorKey.Attributes.Append(setAtributo(doc, "G", colorG.ToString()));
            colorKey.Attributes.Append(setAtributo(doc, "B", colorB.ToString()));
            sprite.AppendChild(colorKey);
            pmml.AppendChild(sprite);

            /*
            doc.AppendChild(XClub);
            System.Xml.XmlNode Pelicula = doc.CreateElement("Pelicula");
            XClub.AppendChild(Pelicula);
            System.Xml.XmlNode Data = doc.CreateElement("Data");
            System.Xml.XmlAttribute atributo = doc.CreateAttribute("Titulo");
            atributo.InnerText = "Garganta Profunda(Deep Throat)";
            Data.Attributes.Append(atributo);
            System.Xml.XmlAttribute atributo2 = doc.CreateAttribute("Director");
            atributo2.InnerText = "";
            Data.Attributes.Append(atributo2);
            Pelicula.AppendChild(Data);*/
            doc.Save(myStream);
        }

        private System.Xml.XmlAttribute setAtributo(System.Xml.XmlDocument doc, string nombre, string valor)
        {
            System.Xml.XmlAttribute atributo;
            atributo = doc.CreateAttribute(nombre);
            atributo.InnerText = valor;
            return atributo;
        }

        // GetRelativeFilename(), by Rob Fisher.
        // rfisher@iee.org
        // http://come.to/robfisher

        // defines
        const int MAX_FILENAME_LEN = 512;

        // The number of characters at the start of an absolute filename.  e.g. in DOS,
        // absolute filenames start with "X:\" so this value should be 3, in UNIX they start
        // with "\" so this value should be 1.
        const int ABSOLUTE_NAME_START = 3;

        // set this to '\\' for DOS or '/' for UNIX
        const char SLASH = '\\';


        // Given the absolute current directory and an absolute file name, returns a relative file name.
        // For example, if the current directory is C:\foo\bar and the filename C:\foo\whee\text.txt is given,
        // GetRelativeFilename will return ..\whee\text.txt.

        private string GetRelativeFilename(string currentDirectory, string absoluteFilename)
        {
            /*
            char a = absoluteFilename[0];
            char b = absoluteFilename[1];
            char c = absoluteFilename[2];
            char d = absoluteFilename[3];
            char e = absoluteFilename[4];
            char f = absoluteFilename[5];
            //if (c.Equals(SLASH.ToCharArray()))
            if (absoluteFilename[2].Equals(SLASH))
                f = "T".ToCharArray()[0];
            else
                f = "F".ToCharArray()[0];
            */
            // declarations - put here so this should work in a C compiler
            int afMarker = 0;
            //int rfMarker = 0;
	        int cdLen = 0, afLen = 0;
	        int i = 0;
	        int levels = 0;
	        string relativeFilename;

	        cdLen = currentDirectory.Length;
	        afLen = absoluteFilename.Length;

	        // make sure the names are not too long or too short
	        if(cdLen > MAX_FILENAME_LEN || cdLen < ABSOLUTE_NAME_START+1 ||
		        afLen > MAX_FILENAME_LEN || afLen < ABSOLUTE_NAME_START+1)
	        {
		        return "";
	        }

	        // Handle DOS names that are on different drives:
	        if(currentDirectory[0] != absoluteFilename[0])
	        {
		        // not on the same drive, so only absolute filename will do
		        relativeFilename = absoluteFilename;
		        return relativeFilename;
	        }

	        // they are on the same drive, find out how much of the current directory
	        // is in the absolute filename
	        i = ABSOLUTE_NAME_START;
	        while(i < afLen && i < cdLen && currentDirectory[i] == absoluteFilename[i])
	        {
		        i++;
	        }

            if (i == cdLen && (absoluteFilename[i].Equals(SLASH) || absoluteFilename[i - 1].Equals(SLASH)))
	        {
		        // the whole current directory name is in the file name,
		        // so we just trim off the current directory name to get the
		        // current file name.
		        if(absoluteFilename[i].Equals(SLASH))
		        {
			        // a directory name might have a trailing slash but a relative
			        // file name should not have a leading one...
			        i++;
		        }

		        relativeFilename = absoluteFilename.Substring(i);
		        return relativeFilename;
	        }


	        // The file is not in a child directory of the current directory, so we
	        // need to step back the appropriate number of parent directories by
	        // using "..\"s.  First find out how many levels deeper we are than the
	        // common directory
	        afMarker = i;
	        levels = 1;
            //i = 0;
	        // count the number of directory levels we have to go up to get to the
	        // common directory
	        while(i < cdLen - 1)
	        {
		        i++;
		        if(currentDirectory[i].Equals(SLASH))
		        {
			        // make sure it's not a trailing slash
			        i++;
			        if(!currentDirectory[i].Equals('\0'))
			        {
				        levels++;
			        }
		        }
	        }

	        // move the absolute filename marker back to the start of the directory name
	        // that it has stopped in.
	        while(afMarker > 0 && !absoluteFilename[afMarker-1].Equals(SLASH))
	        {
		        afMarker--;
	        }

	        // check that the result will not be too long
	        if(levels * 3 + afLen - afMarker > MAX_FILENAME_LEN)
	        {
		        return "";
	        }

	        // add the appropriate number of "..\"s.
	        //rfMarker = 0;
            relativeFilename = "";
	        for(i = 0; i < levels; i++)
	        {
                relativeFilename = relativeFilename.Insert(relativeFilename.Length, ".." + SLASH);
                /*
		        relativeFilename[rfMarker++] = '.';
		        relativeFilename[rfMarker++] = '.';
		        relativeFilename[rfMarker++] = SLASH;
                */
	        }
        
	        // copy the rest of the filename into the result string
            relativeFilename = relativeFilename.Insert(relativeFilename.Length, absoluteFilename.Substring(afMarker));
	        return relativeFilename;
        }

        private void configurarExePathToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            //openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "EXE (*.exe)|*exe";
            //openFileDialog1.FilterIndex = 2;          // Valor de filtro por defecto
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                            exePath = openFileDialog1.FileName;
                            exePath = RemoveFileNameFromPath(exePath);
            }
            exePathLabel.Text = "Exe path: " + exePath;
           
            if (!fileLoc.Equals("") && !exePath.Equals(""))
                relativeFileLoc = GetRelativeFilename(exePath, fileLoc);

            useRelativePath.Enabled = true;
        }

        private String RemoveFileNameFromPath(String path)
        {
            return path.Substring(0,path.LastIndexOf("\\"));
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

    }
}