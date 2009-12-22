// It's sad but the OpenAL C API uses lots and lots of typedefs
// that require wrapper functions (using basic C types) for cgo
// to grok them. So there's a lot more C code here than I would
// like...

// I keep all the alc.h prototypes here for now, for reference.
// They'll go away eventually. Those commented out are already
// accessible from Go.

//ALCcontext *alcCreateContext( ALCdevice *device, const ALCint* attrlist );
//ALCboolean alcMakeContextCurrent( ALCcontext *context );
//void alcProcessContext( ALCcontext *context );
//void alcSuspendContext( ALCcontext *context );
//void alcDestroyContext( ALCcontext *context );
//ALCcontext *alcGetCurrentContext( void );
//ALCdevice *alcGetContextsDevice( ALCcontext *context );
//ALCdevice *alcOpenDevice( const ALCchar *devicename );
ALCdevice *walcOpenDevice(const char *devicename) {
	return alcOpenDevice(devicename);
}
// ALCboolean alcCloseDevice( ALCdevice *device );
// ALCenum alcGetError( ALCdevice *device );
ALCboolean alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname );
void *alcGetProcAddress( ALCdevice *device, const ALCchar *funcname );
ALCenum alcGetEnumValue( ALCdevice *device, const ALCchar *enumname );
const ALCchar *alcGetString( ALCdevice *device, ALCenum param );
//void alcGetIntegerv( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *data );
void walcGetIntegerv(ALCdevice *device, ALCenum param, ALCsizei size, void *data) {
	alcGetIntegerv(device, param, size, data);
}
// ALCdevice *alcCaptureOpenDevice( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );
ALCdevice *walcCaptureOpenDevice(const char *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize) {
	return alcCaptureOpenDevice(devicename, frequency, format, buffersize);
}
// ALCboolean alcCaptureCloseDevice( ALCdevice *device );
// void alcCaptureStart( ALCdevice *device );
// void alcCaptureStop( ALCdevice *device );
// void alcCaptureSamples( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );

// For convenience we offer "singular" versions of the following
// calls as well, which require different wrappers if we want to
// be efficient. The main reason for "singular" versions is that
// Go doesn't allow us to treat a variable as an array.

ALCint walcGetInteger(ALCdevice *device, ALCenum param) {
	ALCint result;
	alcGetIntegerv(device, param, 1, &result);
	return result;
}
