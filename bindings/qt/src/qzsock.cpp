/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZsock::QZsock (zsock_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create a new socket. Returns the new socket, or NULL if the new socket
//  could not be created. Note that the symbol zsock_new (and other       
//  constructors/destructors for zsock) are redirected to the *_checked   
//  variant, enabling intelligent socket leak detection. This can have    
//  performance implications if you use a LOT of sockets. To turn off this
//  redirection behaviour, define ZSOCK_NOCHECK.                          
QZsock::QZsock (int type, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zsock_new (type);
}

///
//  Create a PUB socket. Default action is bind.
QZsock* QZsock::newPub (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_pub (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a SUB socket, and optionally subscribe to some prefix string. Default
//  action is connect.                                                          
QZsock* QZsock::newSub (const QString &endpoint, const QString &subscribe, QObject *qObjParent)
{
    return new QZsock (zsock_new_sub (endpoint.toUtf8().data(), subscribe.toUtf8().data()), qObjParent);
}

///
//  Create a REQ socket. Default action is connect.
QZsock* QZsock::newReq (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_req (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a REP socket. Default action is bind.
QZsock* QZsock::newRep (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_rep (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a DEALER socket. Default action is connect.
QZsock* QZsock::newDealer (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_dealer (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a ROUTER socket. Default action is bind.
QZsock* QZsock::newRouter (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_router (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a PUSH socket. Default action is connect.
QZsock* QZsock::newPush (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_push (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a PULL socket. Default action is bind.
QZsock* QZsock::newPull (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_pull (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create an XPUB socket. Default action is bind.
QZsock* QZsock::newXpub (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_xpub (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create an XSUB socket. Default action is connect.
QZsock* QZsock::newXsub (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_xsub (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a PAIR socket. Default action is connect.
QZsock* QZsock::newPair (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_pair (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a STREAM socket. Default action is connect.
QZsock* QZsock::newStream (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_stream (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a SERVER socket. Default action is bind.
QZsock* QZsock::newServer (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_server (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a CLIENT socket. Default action is connect.
QZsock* QZsock::newClient (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_client (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a RADIO socket. Default action is bind.
QZsock* QZsock::newRadio (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_radio (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a DISH socket. Default action is connect.
QZsock* QZsock::newDish (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_dish (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a GATHER socket. Default action is bind.
QZsock* QZsock::newGather (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_gather (endpoint.toUtf8().data()), qObjParent);
}

///
//  Create a SCATTER socket. Default action is connect.
QZsock* QZsock::newScatter (const QString &endpoint, QObject *qObjParent)
{
    return new QZsock (zsock_new_scatter (endpoint.toUtf8().data()), qObjParent);
}

///
//  Destroy the socket. You must use this for any socket created via the
//  zsock_new method.                                                   
QZsock::~QZsock ()
{
    zsock_destroy (&self);
}

///
//  Bind a socket to a formatted endpoint. For tcp:// endpoints, supports   
//  ephemeral ports, if you specify the port number as "*". By default      
//  zsock uses the IANA designated range from C000 (49152) to FFFF (65535). 
//  To override this range, follow the "*" with "[first-last]". Either or   
//  both first and last may be empty. To bind to a random port within the   
//  range, use "!" in place of "*".                                         
//                                                                          
//  Examples:                                                               
//      tcp://127.0.0.1:*           bind to first free port from C000 up    
//      tcp://127.0.0.1:!           bind to random port from C000 to FFFF   
//      tcp://127.0.0.1:*[60000-]   bind to first free port from 60000 up   
//      tcp://127.0.0.1:![-60000]   bind to random port from C000 to 60000  
//      tcp://127.0.0.1:![55000-55999]                                      
//                                  bind to random port from 55000 to 55999 
//                                                                          
//  On success, returns the actual port number used, for tcp:// endpoints,  
//  and 0 for other transports. On failure, returns -1. Note that when using
//  ephemeral ports, a port may be reused by different services without     
//  clients being aware. Protocols that run on ephemeral ports should take  
//  this into account.                                                      
int QZsock::bind (const QString &param)
{
    int rv = zsock_bind (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Returns last bound endpoint, if any.
const QString QZsock::endpoint ()
{
    const QString rv = QString (zsock_endpoint (self));
    return rv;
}

///
//  Unbind a socket from a formatted endpoint.                     
//  Returns 0 if OK, -1 if the endpoint was invalid or the function
//  isn't supported.                                               
int QZsock::unbind (const QString &param)
{
    int rv = zsock_unbind (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Connect a socket to a formatted endpoint        
//  Returns 0 if OK, -1 if the endpoint was invalid.
int QZsock::connect (const QString &param)
{
    int rv = zsock_connect (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Disconnect a socket from a formatted endpoint                  
//  Returns 0 if OK, -1 if the endpoint was invalid or the function
//  isn't supported.                                               
int QZsock::disconnect (const QString &param)
{
    int rv = zsock_disconnect (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Attach a socket to zero or more endpoints. If endpoints is not null,     
//  parses as list of ZeroMQ endpoints, separated by commas, and prefixed by 
//  '@' (to bind the socket) or '>' (to connect the socket). Returns 0 if all
//  endpoints were valid, or -1 if there was a syntax error. If the endpoint 
//  does not start with '@' or '>', the serverish argument defines whether   
//  it is used to bind (serverish = true) or connect (serverish = false).    
int QZsock::attach (const QString &endpoints, bool serverish)
{
    int rv = zsock_attach (self, endpoints.toUtf8().data(), serverish);
    return rv;
}

///
//  Returns socket type as printable constant string.
const QString QZsock::typeStr ()
{
    const QString rv = QString (zsock_type_str (self));
    return rv;
}

///
//  Send a 'picture' message to the socket (or actor). The picture is a   
//  string that defines the type of each frame. This makes it easy to send
//  a complex multiframe message in one call. The picture can contain any 
//  of these characters, each corresponding to one or two arguments:      
//                                                                        
//      i = int (signed)                                                  
//      1 = uint8_t                                                       
//      2 = uint16_t                                                      
//      4 = uint32_t                                                      
//      8 = uint64_t                                                      
//      s = char *                                                        
//      b = byte *, size_t (2 arguments)                                  
//      c = zchunk_t *                                                    
//      f = zframe_t *                                                    
//      h = zhashx_t *                                                    
//      U = zuuid_t *                                                     
//      p = void * (sends the pointer value, only meaningful over inproc) 
//      m = zmsg_t * (sends all frames in the zmsg)                       
//      z = sends zero-sized frame (0 arguments)                          
//      u = uint (deprecated)                                             
//                                                                        
//  Note that s, b, c, and f are encoded the same way and the choice is   
//  offered as a convenience to the sender, which may or may not already  
//  have data in a zchunk or zframe. Does not change or take ownership of 
//  any arguments. Returns 0 if successful, -1 if sending failed for any  
//  reason.                                                               
int QZsock::send (const QString &picture,  ...)
{
    va_list args;
    va_start (args, picture);
    int rv = zsock_vsend (self, picture.toUtf8().data(), args);
    va_end (args);
    return rv;
}

///
//  Send a 'picture' message to the socket (or actor). This is a va_list 
//  version of zsock_send (), so please consult its documentation for the
//  details.                                                             
int QZsock::vsend (const QString &picture, va_list argptr)
{
    int rv = zsock_vsend (self, picture.toUtf8().data(), argptr);
    return rv;
}

///
//  Receive a 'picture' message to the socket (or actor). See zsock_send for
//  the format and meaning of the picture. Returns the picture elements into
//  a series of pointers as provided by the caller:                         
//                                                                          
//      i = int * (stores signed integer)                                   
//      4 = uint32_t * (stores 32-bit unsigned integer)                     
//      8 = uint64_t * (stores 64-bit unsigned integer)                     
//      s = char ** (allocates new string)                                  
//      b = byte **, size_t * (2 arguments) (allocates memory)              
//      c = zchunk_t ** (creates zchunk)                                    
//      f = zframe_t ** (creates zframe)                                    
//      U = zuuid_t * (creates a zuuid with the data)                       
//      h = zhashx_t ** (creates zhashx)                                    
//      p = void ** (stores pointer)                                        
//      m = zmsg_t ** (creates a zmsg with the remaing frames)              
//      z = null, asserts empty frame (0 arguments)                         
//      u = uint * (stores unsigned integer, deprecated)                    
//                                                                          
//  Note that zsock_recv creates the returned objects, and the caller must  
//  destroy them when finished with them. The supplied pointers do not need 
//  to be initialized. Returns 0 if successful, or -1 if it failed to recv  
//  a message, in which case the pointers are not modified. When message    
//  frames are truncated (a short message), sets return values to zero/null.
//  If an argument pointer is NULL, does not store any value (skips it).    
//  An 'n' picture matches an empty frame; if the message does not match,   
//  the method will return -1.                                              
int QZsock::recv (const QString &picture,  ...)
{
    va_list args;
    va_start (args, picture);
    int rv = zsock_vrecv (self, picture.toUtf8().data(), args);
    va_end (args);
    return rv;
}

///
//  Receive a 'picture' message from the socket (or actor). This is a    
//  va_list version of zsock_recv (), so please consult its documentation
//  for the details.                                                     
int QZsock::vrecv (const QString &picture, va_list argptr)
{
    int rv = zsock_vrecv (self, picture.toUtf8().data(), argptr);
    return rv;
}

///
//  Return socket routing ID if any. This returns 0 if the socket is not
//  of type ZMQ_SERVER or if no request was already received on it.     
quint32 QZsock::routingId ()
{
    uint32_t rv = zsock_routing_id (self);
    return rv;
}

///
//  Set routing ID on socket. The socket MUST be of type ZMQ_SERVER.        
//  This will be used when sending messages on the socket via the zsock API.
void QZsock::setRoutingId (quint32 routingId)
{
    zsock_set_routing_id (self, (uint32_t) routingId);
    
}

///
//  Set socket to use unbounded pipes (HWM=0); use this in cases when you are
//  totally certain the message volume can fit in memory. This method works  
//  across all versions of ZeroMQ. Takes a polymorphic socket reference.     
void QZsock::setUnbounded ()
{
    zsock_set_unbounded (self);
    
}

///
//  Send a signal over a socket. A signal is a short message carrying a   
//  success/failure code (by convention, 0 means OK). Signals are encoded 
//  to be distinguishable from "normal" messages. Accepts a zsock_t or a  
//  zactor_t argument, and returns 0 if successful, -1 if the signal could
//  not be sent. Takes a polymorphic socket reference.                    
int QZsock::signal (byte status)
{
    int rv = zsock_signal (self, status);
    return rv;
}

///
//  Wait on a signal. Use this to coordinate between threads, over pipe  
//  pairs. Blocks until the signal is received. Returns -1 on error, 0 or
//  greater on success. Accepts a zsock_t or a zactor_t as argument.     
//  Takes a polymorphic socket reference.                                
int QZsock::wait ()
{
    int rv = zsock_wait (self);
    return rv;
}

///
//  If there is a partial message still waiting on the socket, remove and    
//  discard it. This is useful when reading partial messages, to get specific
//  message types.                                                           
void QZsock::flush ()
{
    zsock_flush (self);
    
}

///
//  Join a group for the RADIO-DISH pattern. Call only on ZMQ_DISH.
//  Returns 0 if OK, -1 if failed.                                 
int QZsock::join (const QString &group)
{
    int rv = zsock_join (self, group.toUtf8().data());
    return rv;
}

///
//  Leave a group for the RADIO-DISH pattern. Call only on ZMQ_DISH.
//  Returns 0 if OK, -1 if failed.                                  
int QZsock::leave (const QString &group)
{
    int rv = zsock_leave (self, group.toUtf8().data());
    return rv;
}

///
//  Probe the supplied object, and report if it looks like a zsock_t.
//  Takes a polymorphic socket reference.                            
bool QZsock::is (void *self)
{
    bool rv = zsock_is (self);
    return rv;
}

///
//  Probe the supplied reference. If it looks like a zsock_t instance, return
//  the underlying libzmq socket handle; else if it looks like a file        
//  descriptor, return NULL; else if it looks like a libzmq socket handle,   
//  return the supplied value. Takes a polymorphic socket reference.         
void * QZsock::resolve (void *self)
{
    void * rv = zsock_resolve (self);
    return rv;
}

///
//  Get socket option `heartbeat_ivl`.
int QZsock::heartbeatIvl ()
{
    int rv = zsock_heartbeat_ivl (self);
    return rv;
}

///
//  Set socket option `heartbeat_ivl`.
void QZsock::setHeartbeatIvl (int heartbeatIvl)
{
    zsock_set_heartbeat_ivl (self, heartbeatIvl);
    
}

///
//  Get socket option `heartbeat_ttl`.
int QZsock::heartbeatTtl ()
{
    int rv = zsock_heartbeat_ttl (self);
    return rv;
}

///
//  Set socket option `heartbeat_ttl`.
void QZsock::setHeartbeatTtl (int heartbeatTtl)
{
    zsock_set_heartbeat_ttl (self, heartbeatTtl);
    
}

///
//  Get socket option `heartbeat_timeout`.
int QZsock::heartbeatTimeout ()
{
    int rv = zsock_heartbeat_timeout (self);
    return rv;
}

///
//  Set socket option `heartbeat_timeout`.
void QZsock::setHeartbeatTimeout (int heartbeatTimeout)
{
    zsock_set_heartbeat_timeout (self, heartbeatTimeout);
    
}

///
//  Get socket option `use_fd`.
int QZsock::useFd ()
{
    int rv = zsock_use_fd (self);
    return rv;
}

///
//  Set socket option `use_fd`.
void QZsock::setUseFd (int useFd)
{
    zsock_set_use_fd (self, useFd);
    
}

///
//  Get socket option `tos`.
int QZsock::tos ()
{
    int rv = zsock_tos (self);
    return rv;
}

///
//  Set socket option `tos`.
void QZsock::setTos (int tos)
{
    zsock_set_tos (self, tos);
    
}

///
//  Set socket option `router_handover`.
void QZsock::setRouterHandover (int routerHandover)
{
    zsock_set_router_handover (self, routerHandover);
    
}

///
//  Set socket option `router_mandatory`.
void QZsock::setRouterMandatory (int routerMandatory)
{
    zsock_set_router_mandatory (self, routerMandatory);
    
}

///
//  Set socket option `probe_router`.
void QZsock::setProbeRouter (int probeRouter)
{
    zsock_set_probe_router (self, probeRouter);
    
}

///
//  Set socket option `req_relaxed`.
void QZsock::setReqRelaxed (int reqRelaxed)
{
    zsock_set_req_relaxed (self, reqRelaxed);
    
}

///
//  Set socket option `req_correlate`.
void QZsock::setReqCorrelate (int reqCorrelate)
{
    zsock_set_req_correlate (self, reqCorrelate);
    
}

///
//  Set socket option `conflate`.
void QZsock::setConflate (int conflate)
{
    zsock_set_conflate (self, conflate);
    
}

///
//  Get socket option `zap_domain`.
QString QZsock::zapDomain ()
{
    char *retStr_ = zsock_zap_domain (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `zap_domain`.
void QZsock::setZapDomain (const QString &zapDomain)
{
    zsock_set_zap_domain (self, zapDomain.toUtf8().data());
    
}

///
//  Get socket option `mechanism`.
int QZsock::mechanism ()
{
    int rv = zsock_mechanism (self);
    return rv;
}

///
//  Get socket option `plain_server`.
int QZsock::plainServer ()
{
    int rv = zsock_plain_server (self);
    return rv;
}

///
//  Set socket option `plain_server`.
void QZsock::setPlainServer (int plainServer)
{
    zsock_set_plain_server (self, plainServer);
    
}

///
//  Get socket option `plain_username`.
QString QZsock::plainUsername ()
{
    char *retStr_ = zsock_plain_username (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `plain_username`.
void QZsock::setPlainUsername (const QString &plainUsername)
{
    zsock_set_plain_username (self, plainUsername.toUtf8().data());
    
}

///
//  Get socket option `plain_password`.
QString QZsock::plainPassword ()
{
    char *retStr_ = zsock_plain_password (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `plain_password`.
void QZsock::setPlainPassword (const QString &plainPassword)
{
    zsock_set_plain_password (self, plainPassword.toUtf8().data());
    
}

///
//  Get socket option `curve_server`.
int QZsock::curveServer ()
{
    int rv = zsock_curve_server (self);
    return rv;
}

///
//  Set socket option `curve_server`.
void QZsock::setCurveServer (int curveServer)
{
    zsock_set_curve_server (self, curveServer);
    
}

///
//  Get socket option `curve_publickey`.
QString QZsock::curvePublickey ()
{
    char *retStr_ = zsock_curve_publickey (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `curve_publickey`.
void QZsock::setCurvePublickey (const QString &curvePublickey)
{
    zsock_set_curve_publickey (self, curvePublickey.toUtf8().data());
    
}

///
//  Set socket option `curve_publickey` from 32-octet binary
void QZsock::setCurvePublickeyBin (const byte *curvePublickey)
{
    zsock_set_curve_publickey_bin (self, curvePublickey);
    
}

///
//  Get socket option `curve_secretkey`.
QString QZsock::curveSecretkey ()
{
    char *retStr_ = zsock_curve_secretkey (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `curve_secretkey`.
void QZsock::setCurveSecretkey (const QString &curveSecretkey)
{
    zsock_set_curve_secretkey (self, curveSecretkey.toUtf8().data());
    
}

///
//  Set socket option `curve_secretkey` from 32-octet binary
void QZsock::setCurveSecretkeyBin (const byte *curveSecretkey)
{
    zsock_set_curve_secretkey_bin (self, curveSecretkey);
    
}

///
//  Get socket option `curve_serverkey`.
QString QZsock::curveServerkey ()
{
    char *retStr_ = zsock_curve_serverkey (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `curve_serverkey`.
void QZsock::setCurveServerkey (const QString &curveServerkey)
{
    zsock_set_curve_serverkey (self, curveServerkey.toUtf8().data());
    
}

///
//  Set socket option `curve_serverkey` from 32-octet binary
void QZsock::setCurveServerkeyBin (const byte *curveServerkey)
{
    zsock_set_curve_serverkey_bin (self, curveServerkey);
    
}

///
//  Get socket option `gssapi_server`.
int QZsock::gssapiServer ()
{
    int rv = zsock_gssapi_server (self);
    return rv;
}

///
//  Set socket option `gssapi_server`.
void QZsock::setGssapiServer (int gssapiServer)
{
    zsock_set_gssapi_server (self, gssapiServer);
    
}

///
//  Get socket option `gssapi_plaintext`.
int QZsock::gssapiPlaintext ()
{
    int rv = zsock_gssapi_plaintext (self);
    return rv;
}

///
//  Set socket option `gssapi_plaintext`.
void QZsock::setGssapiPlaintext (int gssapiPlaintext)
{
    zsock_set_gssapi_plaintext (self, gssapiPlaintext);
    
}

///
//  Get socket option `gssapi_principal`.
QString QZsock::gssapiPrincipal ()
{
    char *retStr_ = zsock_gssapi_principal (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `gssapi_principal`.
void QZsock::setGssapiPrincipal (const QString &gssapiPrincipal)
{
    zsock_set_gssapi_principal (self, gssapiPrincipal.toUtf8().data());
    
}

///
//  Get socket option `gssapi_service_principal`.
QString QZsock::gssapiServicePrincipal ()
{
    char *retStr_ = zsock_gssapi_service_principal (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `gssapi_service_principal`.
void QZsock::setGssapiServicePrincipal (const QString &gssapiServicePrincipal)
{
    zsock_set_gssapi_service_principal (self, gssapiServicePrincipal.toUtf8().data());
    
}

///
//  Get socket option `ipv6`.
int QZsock::ipv6 ()
{
    int rv = zsock_ipv6 (self);
    return rv;
}

///
//  Set socket option `ipv6`.
void QZsock::setIpv6 (int ipv6)
{
    zsock_set_ipv6 (self, ipv6);
    
}

///
//  Get socket option `immediate`.
int QZsock::immediate ()
{
    int rv = zsock_immediate (self);
    return rv;
}

///
//  Set socket option `immediate`.
void QZsock::setImmediate (int immediate)
{
    zsock_set_immediate (self, immediate);
    
}

///
//  Set socket option `router_raw`.
void QZsock::setRouterRaw (int routerRaw)
{
    zsock_set_router_raw (self, routerRaw);
    
}

///
//  Get socket option `ipv4only`.
int QZsock::ipv4only ()
{
    int rv = zsock_ipv4only (self);
    return rv;
}

///
//  Set socket option `ipv4only`.
void QZsock::setIpv4only (int ipv4only)
{
    zsock_set_ipv4only (self, ipv4only);
    
}

///
//  Set socket option `delay_attach_on_connect`.
void QZsock::setDelayAttachOnConnect (int delayAttachOnConnect)
{
    zsock_set_delay_attach_on_connect (self, delayAttachOnConnect);
    
}

///
//  Get socket option `type`.
int QZsock::type ()
{
    int rv = zsock_type (self);
    return rv;
}

///
//  Get socket option `sndhwm`.
int QZsock::sndhwm ()
{
    int rv = zsock_sndhwm (self);
    return rv;
}

///
//  Set socket option `sndhwm`.
void QZsock::setSndhwm (int sndhwm)
{
    zsock_set_sndhwm (self, sndhwm);
    
}

///
//  Get socket option `rcvhwm`.
int QZsock::rcvhwm ()
{
    int rv = zsock_rcvhwm (self);
    return rv;
}

///
//  Set socket option `rcvhwm`.
void QZsock::setRcvhwm (int rcvhwm)
{
    zsock_set_rcvhwm (self, rcvhwm);
    
}

///
//  Get socket option `affinity`.
int QZsock::affinity ()
{
    int rv = zsock_affinity (self);
    return rv;
}

///
//  Set socket option `affinity`.
void QZsock::setAffinity (int affinity)
{
    zsock_set_affinity (self, affinity);
    
}

///
//  Set socket option `subscribe`.
void QZsock::setSubscribe (const QString &subscribe)
{
    zsock_set_subscribe (self, subscribe.toUtf8().data());
    
}

///
//  Set socket option `unsubscribe`.
void QZsock::setUnsubscribe (const QString &unsubscribe)
{
    zsock_set_unsubscribe (self, unsubscribe.toUtf8().data());
    
}

///
//  Get socket option `identity`.
QString QZsock::identity ()
{
    char *retStr_ = zsock_identity (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `identity`.
void QZsock::setIdentity (const QString &identity)
{
    zsock_set_identity (self, identity.toUtf8().data());
    
}

///
//  Get socket option `rate`.
int QZsock::rate ()
{
    int rv = zsock_rate (self);
    return rv;
}

///
//  Set socket option `rate`.
void QZsock::setRate (int rate)
{
    zsock_set_rate (self, rate);
    
}

///
//  Get socket option `recovery_ivl`.
int QZsock::recoveryIvl ()
{
    int rv = zsock_recovery_ivl (self);
    return rv;
}

///
//  Set socket option `recovery_ivl`.
void QZsock::setRecoveryIvl (int recoveryIvl)
{
    zsock_set_recovery_ivl (self, recoveryIvl);
    
}

///
//  Get socket option `sndbuf`.
int QZsock::sndbuf ()
{
    int rv = zsock_sndbuf (self);
    return rv;
}

///
//  Set socket option `sndbuf`.
void QZsock::setSndbuf (int sndbuf)
{
    zsock_set_sndbuf (self, sndbuf);
    
}

///
//  Get socket option `rcvbuf`.
int QZsock::rcvbuf ()
{
    int rv = zsock_rcvbuf (self);
    return rv;
}

///
//  Set socket option `rcvbuf`.
void QZsock::setRcvbuf (int rcvbuf)
{
    zsock_set_rcvbuf (self, rcvbuf);
    
}

///
//  Get socket option `linger`.
int QZsock::linger ()
{
    int rv = zsock_linger (self);
    return rv;
}

///
//  Set socket option `linger`.
void QZsock::setLinger (int linger)
{
    zsock_set_linger (self, linger);
    
}

///
//  Get socket option `reconnect_ivl`.
int QZsock::reconnectIvl ()
{
    int rv = zsock_reconnect_ivl (self);
    return rv;
}

///
//  Set socket option `reconnect_ivl`.
void QZsock::setReconnectIvl (int reconnectIvl)
{
    zsock_set_reconnect_ivl (self, reconnectIvl);
    
}

///
//  Get socket option `reconnect_ivl_max`.
int QZsock::reconnectIvlMax ()
{
    int rv = zsock_reconnect_ivl_max (self);
    return rv;
}

///
//  Set socket option `reconnect_ivl_max`.
void QZsock::setReconnectIvlMax (int reconnectIvlMax)
{
    zsock_set_reconnect_ivl_max (self, reconnectIvlMax);
    
}

///
//  Get socket option `backlog`.
int QZsock::backlog ()
{
    int rv = zsock_backlog (self);
    return rv;
}

///
//  Set socket option `backlog`.
void QZsock::setBacklog (int backlog)
{
    zsock_set_backlog (self, backlog);
    
}

///
//  Get socket option `maxmsgsize`.
int QZsock::maxmsgsize ()
{
    int rv = zsock_maxmsgsize (self);
    return rv;
}

///
//  Set socket option `maxmsgsize`.
void QZsock::setMaxmsgsize (int maxmsgsize)
{
    zsock_set_maxmsgsize (self, maxmsgsize);
    
}

///
//  Get socket option `multicast_hops`.
int QZsock::multicastHops ()
{
    int rv = zsock_multicast_hops (self);
    return rv;
}

///
//  Set socket option `multicast_hops`.
void QZsock::setMulticastHops (int multicastHops)
{
    zsock_set_multicast_hops (self, multicastHops);
    
}

///
//  Get socket option `rcvtimeo`.
int QZsock::rcvtimeo ()
{
    int rv = zsock_rcvtimeo (self);
    return rv;
}

///
//  Set socket option `rcvtimeo`.
void QZsock::setRcvtimeo (int rcvtimeo)
{
    zsock_set_rcvtimeo (self, rcvtimeo);
    
}

///
//  Get socket option `sndtimeo`.
int QZsock::sndtimeo ()
{
    int rv = zsock_sndtimeo (self);
    return rv;
}

///
//  Set socket option `sndtimeo`.
void QZsock::setSndtimeo (int sndtimeo)
{
    zsock_set_sndtimeo (self, sndtimeo);
    
}

///
//  Set socket option `xpub_verbose`.
void QZsock::setXpubVerbose (int xpubVerbose)
{
    zsock_set_xpub_verbose (self, xpubVerbose);
    
}

///
//  Get socket option `tcp_keepalive`.
int QZsock::tcpKeepalive ()
{
    int rv = zsock_tcp_keepalive (self);
    return rv;
}

///
//  Set socket option `tcp_keepalive`.
void QZsock::setTcpKeepalive (int tcpKeepalive)
{
    zsock_set_tcp_keepalive (self, tcpKeepalive);
    
}

///
//  Get socket option `tcp_keepalive_idle`.
int QZsock::tcpKeepaliveIdle ()
{
    int rv = zsock_tcp_keepalive_idle (self);
    return rv;
}

///
//  Set socket option `tcp_keepalive_idle`.
void QZsock::setTcpKeepaliveIdle (int tcpKeepaliveIdle)
{
    zsock_set_tcp_keepalive_idle (self, tcpKeepaliveIdle);
    
}

///
//  Get socket option `tcp_keepalive_cnt`.
int QZsock::tcpKeepaliveCnt ()
{
    int rv = zsock_tcp_keepalive_cnt (self);
    return rv;
}

///
//  Set socket option `tcp_keepalive_cnt`.
void QZsock::setTcpKeepaliveCnt (int tcpKeepaliveCnt)
{
    zsock_set_tcp_keepalive_cnt (self, tcpKeepaliveCnt);
    
}

///
//  Get socket option `tcp_keepalive_intvl`.
int QZsock::tcpKeepaliveIntvl ()
{
    int rv = zsock_tcp_keepalive_intvl (self);
    return rv;
}

///
//  Set socket option `tcp_keepalive_intvl`.
void QZsock::setTcpKeepaliveIntvl (int tcpKeepaliveIntvl)
{
    zsock_set_tcp_keepalive_intvl (self, tcpKeepaliveIntvl);
    
}

///
//  Get socket option `tcp_accept_filter`.
QString QZsock::tcpAcceptFilter ()
{
    char *retStr_ = zsock_tcp_accept_filter (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Set socket option `tcp_accept_filter`.
void QZsock::setTcpAcceptFilter (const QString &tcpAcceptFilter)
{
    zsock_set_tcp_accept_filter (self, tcpAcceptFilter.toUtf8().data());
    
}

///
//  Get socket option `rcvmore`.
int QZsock::rcvmore ()
{
    int rv = zsock_rcvmore (self);
    return rv;
}

///
//  Get socket option `fd`.
SOCKET QZsock::fd ()
{
    SOCKET rv = zsock_fd (self);
    return rv;
}

///
//  Get socket option `events`.
int QZsock::events ()
{
    int rv = zsock_events (self);
    return rv;
}

///
//  Get socket option `last_endpoint`.
QString QZsock::lastEndpoint ()
{
    char *retStr_ = zsock_last_endpoint (self);
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Self test of this class.
void QZsock::test (bool verbose)
{
    zsock_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
