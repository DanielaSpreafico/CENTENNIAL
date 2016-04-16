package org.opendaylight.yang.gen.v1.uri.onf.microwavemodel.objectclasses.mwconnection.rev160323.containercapability;
import org.opendaylight.yangtools.yang.binding.Identifier;
import org.opendaylight.yang.gen.v1.uri.onf.coremodel.corefoundationmodule.superclassesandcommonpackages.rev160305.UniversalId;


public class AvailableKindsOfContainerListKey
 implements Identifier<AvailableKindsOfContainerList> {
    private static final long serialVersionUID = 612491639166449947L;
    private final UniversalId _uuid;


    public AvailableKindsOfContainerListKey(UniversalId _uuid) {
    
    
        this._uuid = _uuid;
    }
    
    /**
     * Creates a copy from Source Object.
     *
     * @param source Source object
     */
    public AvailableKindsOfContainerListKey(AvailableKindsOfContainerListKey source) {
        this._uuid = source._uuid;
    }


    public UniversalId getUuid() {
        return _uuid;
    }


    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((_uuid == null) ? 0 : _uuid.hashCode());
        return result;
    }

    @Override
    public boolean equals(java.lang.Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        AvailableKindsOfContainerListKey other = (AvailableKindsOfContainerListKey) obj;
        if (_uuid == null) {
            if (other._uuid != null) {
                return false;
            }
        } else if(!_uuid.equals(other._uuid)) {
            return false;
        }
        return true;
    }

    @Override
    public java.lang.String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder(org.opendaylight.yang.gen.v1.uri.onf.microwavemodel.objectclasses.mwconnection.rev160323.containercapability.AvailableKindsOfContainerListKey.class.getSimpleName()).append(" [");
        boolean first = true;
    
        if (_uuid != null) {
            if (first) {
                first = false;
            } else {
                builder.append(", ");
            }
            builder.append("_uuid=");
            builder.append(_uuid);
         }
        return builder.append(']').toString();
    }



}

