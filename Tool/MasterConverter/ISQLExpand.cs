using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterConverter
{

	/// <summary>
	/// SQL展開インタフェース
	/// </summary>
	public interface ISQLExpand
	{

		/// <summary>
		/// 展開.
		/// </summary>
		/// <param name="FileList">ファイルリスト</param>
		/// <returns>成功したらtrueを返す。</returns>
		bool Expand(string[] FileList);

	}
}
