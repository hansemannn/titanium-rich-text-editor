package ti.editor;

import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.util.TiRHelper;

import android.content.Context;
import android.os.Build;
import android.support.v4.content.ContextCompat;


public class Utils {
	public static int getR(String path) {
		try {
			return TiRHelper.getResource(path);
			
		} catch (Exception exc) {
			return -1;
		}
	}
	
	@SuppressWarnings("deprecation")
	public static int getColor(String intResName) {
		try {
			int colorId = getR("color." + intResName);
			
			if (colorId == -1) {
				return -1;
				
			} else {
				Context context = TiApplication.getInstance().getApplicationContext();
				return context.getResources().getColor(colorId);
			}
		} catch (Exception exc) {
			return -1;
		}
	}
}