/*!
 * Debug/functions.inc
 *
 > Priority: 0
 */

stock this.LogLevel(level, string:message[], va_args<>) {
	// Format all arguments to one string
	new debugLine[MAX_LINE_LENGTH];
	va_format(debugLine, sizeof(debugLine), message, va_start<2>);
	// Combine the line with the debug level
	printf("[DEBUG - %s] %s", this.LEVELS[level], debugLine);
}

stock this.Info(string:message[], va_args<>) {
	this.LogLevel(0, va_return(message, va_start<1>));
}

stock this.Log(string:message[], va_args<>) {
	this.LogLevel(0, va_return(message, va_start<1>));
}

stock this.Warn(string:message[], va_args<>) {
	this.LogLevel(1, va_return(message, va_start<1>));
}

stock this.Error(string:message[], va_args<>) {
	this.LogLevel(2, va_return(message, va_start<1>));
}