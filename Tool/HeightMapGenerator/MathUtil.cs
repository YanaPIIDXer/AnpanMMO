using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeightMapGenerator
{

	/// <summary>
	/// 計算ユーティリティ
	/// </summary>
	public class MathUtil
	{

		/// <summary>
		/// 補間.
		/// </summary>
		/// <param name="Start">開始</param>
		/// <param name="End">終了</param>
		/// <param name="Rate">レート</param>
		/// <returns>補間結果</returns>
		public static float Lerp(float Start, float End, float Rate)
		{
			if(Rate > 1.0f)
			{
				Rate = 1.0f;
			}
			if(Rate < 0.0f)
			{
				Rate = 0.0f;
			}
			return ((1.0f - Rate) * Start + Rate * End);
		}

	}
}
