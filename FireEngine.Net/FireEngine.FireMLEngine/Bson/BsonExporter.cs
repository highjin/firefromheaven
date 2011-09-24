using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MongoDB.Bson.Serialization;
using MongoDB.Bson.IO;
using System.IO;

namespace FireEngine.FireMLEngine.Bson
{
    /// <summary>
    /// Export the FireMLRoot to a Bson file.
    /// </summary>
    public class BsonExporter
    {
        private FireMLRoot root;

        public BsonExporter(FireMLRoot root)
        {
            this.root = root;
        }

        public void Export()
        {

        }
    }
}
